/*test machine: CSELAB_machine_name * date: mm/dd/yy
* name: full_name1 , [full_name2]
* x500: id_for_first_name , [id_for_second_name] */
#define _BSD_SOURCE
#define _DEFAULT_SOURCE
#include "../include/phase2.h"
#include "../include/protocol.h"


// count first letter in each word on each line and sum in an array to be
// sent to server
void map(int id, int sockfd, char* path){
  FILE* txtPtr;
  if ((txtPtr = fopen(path,"r")) == NULL){
    printf("Error reading text file\n");
    return;
  }
  else{
    int charCounts[26];
    for (int i = 0; i < 26; i++){
      charCounts[i] = 0;
    }
    // max line size
    char line[256];
    // iterate line by line in file
    while(fgets(line,sizeof(line),txtPtr)){
      // 97 is ASCII code for 'a', so take int value of c retrieved
      // and increment correct letter in tArray
      char c = tolower(line[0]);
      charCounts[((int)c) - 97]++;
    }
    // UPDATE_AZLIST: The request sent to update the list stored on server
    int request[REQUEST_MSG_SIZE];
    request[0] = UPDATE_AZLIST;
    request[1] = id;
    for(int i = 2; i < 28; i++){request[i] = htons(charCounts[i-2]);}
    int response[RESPONSE_MSG_SIZE];
    write(sockfd,(void *) request, sizeof(int) * REQUEST_MSG_SIZE);
    read(sockfd, response, sizeof(int)*RESPONSE_MSG_SIZE);
  }
  return;
}

void phase2(int id, char *server_ip, int server_port){
  int sockfd = socket(AF_INET , SOCK_STREAM , 0);
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_port = htons(server_port);
  address.sin_addr.s_addr = inet_addr(server_ip);

  // connect to socket on server side
  if (connect(sockfd, (struct sockaddr *) &address, sizeof(address)) == 0){
    FILE *logPtr;
    logPtr = fopen("log/log_client.txt","a");
    fprintf(logPtr,"[%d] open connection\n", id);
    //fclose(logPtr);


    char cwd[1024];
    getcwd(cwd,sizeof(cwd));
    strcat(cwd,"/MapperInput/Mapper_");

    // go to appropiate /MapperInput/Mapper_i file that was designated to process
    // running this instance of phase2
    char number[3];
    sprintf(number, "%d", id);
    strcat(cwd,number);
    strcat(cwd,".txt");
    FILE* fPtr;
    if ((fPtr = fopen(cwd, "r")) == NULL){
      printf("Error reading file: %s\n", cwd);
      return;
    }

    // retrieve a file path from Mapper_i file and run map, until all file paths
    // have been processed
    char newpath[1024];

    int response[3];
    // CHECK IN
    int request[REQUEST_MSG_SIZE];
    request[0] = CHECKIN;
    request[1] = id;
    for (int i = 2; i < 28; i++){ request[i] = 0; }
    write(sockfd, (void *) request, sizeof(int)* REQUEST_MSG_SIZE);
    read(sockfd, response, sizeof(int) * RESPONSE_MSG_SIZE);

    //logPtr = fopen("log/log_client.txt","a");
    fprintf(logPtr,"[%d] CHECKIN: %d %d\n",id,response[1],response[2]);
    fclose(logPtr);

    // something bad happens here, client refuses to continue to document Commands
    // and responses in log_client.txt yet server side shows clients continuing
    // to make all deterministic requests.
    int request_count = 0;
    while(fgets(newpath,sizeof(newpath),fPtr)){
      strtok(newpath,"\n");
      map(id,sockfd,newpath);
      request_count++;
    }
    // FINAL UPDATE_AZLIST MESSAGE
    //logPtr = fopen("log/log_client.txt","a");
    fprintf(logPtr,"[%d] UPDATE_AZLIST: %d\n", id, request_count);
    //fclose(logPtr);

    // GET_AZLIST
    request[0] = GET_AZLIST;
    for (int i = 2; i < 28; i++){request[i] = 0;}
    write(sockfd, (void *) request, sizeof(int)* REQUEST_MSG_SIZE);
    int long_response[LONG_RESPONSE_MSG_SIZE];
    read(sockfd, long_response, sizeof(int) * LONG_RESPONSE_MSG_SIZE);
    //logPtr = fopen("log/log_client.txt","a");
    fprintf(logPtr,"[%d] GET_AZLIST: %d", id, long_response[1]);
    for(int i = 2; i < 28; i++){
      fprintf(logPtr," %d", ntohs(long_response[i]));
    }
    fprintf(logPtr,"\n");
    //fclose(logPtr);


    // GET_MAPPER_UPDATES
    request[0] = GET_MAPPER_UPDATES;
    write(sockfd, (void *) request, sizeof(int)* REQUEST_MSG_SIZE);
    read(sockfd, response, sizeof(int) * RESPONSE_MSG_SIZE);
    //logPtr = fopen("log/log_client.txt","a");
    fprintf(logPtr, "[%d] GET_MAPPER_UPDATES: %d %d\n", id, response[1],response[2]);
    //fclose(logPtr);

    // GET_ALL_UPDATES
    request[0] = GET_ALL_UPDATES;
    write(sockfd, (void *) request, sizeof(int)* REQUEST_MSG_SIZE);
    read(sockfd, response, sizeof(int) * RESPONSE_MSG_SIZE);
    //logPtr = fopen("log/log_client.txt","a");
    fprintf(logPtr, "[%d] GET_ALL_UPDATES: %d %d\n", id, response[1],response[2]);
    //fclose(logPtr);

    // CHECK OUT
    request[0] = CHECKOUT;
    write(sockfd, (void *) request, sizeof(int)*REQUEST_MSG_SIZE);
    read(sockfd, response, sizeof(int) * RESPONSE_MSG_SIZE);
    //logPtr = fopen("log/log_client.txt","a");
    fprintf(logPtr,"[%d] CHECKOUT: %d %d\n",id,response[1],response[2]);
    //fclose(logPtr);

    // closing connection
    close(sockfd);
    //logPtr = fopen("log/log_client.txt","a");
    fprintf(logPtr,"[%d] close connection\n", id);
    fclose(logPtr);
  }
  else{
    perror("Connection failed!");
  }
  return;
}
