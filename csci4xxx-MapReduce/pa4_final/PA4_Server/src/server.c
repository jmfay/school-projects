/*test machine: CSELAB_machine_name * date: mm/dd/yy
* name: full_name1 , [full_name2]
* x500: id_for_first_name , [id_for_second_name] */

#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
//#include <zconf.h>
#include <pthread.h>
#include <signal.h>
#include <arpa/inet.h>
#include "../include/protocol.h"

#define MAX_CONCURRENT 50

int currentConn = 0;
pthread_mutex_t currentConn_lock;
pthread_mutex_t azList_lock;
pthread_mutex_t updateTable_lock;

// struct for thread to handle a connection
struct threadArg {
	int clientfd;
	char * clientip;
	int clientport;
};

// struct for updateTable entries
struct updateEntry {
  int id;
  int updates;
  int checkflag;
};

// global data structures for multithreaded server, use mutexes to access
struct updateEntry updateStatusTable[50];
int azList[26];

// increase a updateEntry's # of update by 1
int incrementStatus(int id){
  for(int i = 0; i < 50; i++){
    if (updateStatusTable[i].id == id){
      updateStatusTable[i].updates++;
      return 0;
    }
  }
  return -1;
}

// make new struct to be placed in updateStatusTable
int addEntry(int id){
  struct updateEntry newEntry = {id, 0, 1};
  for(int i = 0; i < 50; i++){
    if (updateStatusTable[i].id == -2){
      updateStatusTable[i] = newEntry;
      return 0;
    }
  }
  return -1;
}

// thread function for server.
void * reducer(void * arg) {
  int checkout = 0;
  struct threadArg * tArg = (struct threadArg *) arg;
	int request[REQUEST_MSG_SIZE];
  while (checkout != 1){
    read(tArg->clientfd, request,sizeof(int) * REQUEST_MSG_SIZE);
    // Use a mutex at some point to lock access to azList table and updateTable?
    int response[RESPONSE_MSG_SIZE] = {0,0,0};
    int updates = 0;

    // switch case to handle each type of request
    switch(request[RQS_COMMAND_ID]){

      case CHECKIN:
        // if statement to check if already checked in
        printf("[%d] CHECKIN\n", request[RQS_MAPPER_PID]);
        response[0] = CHECKIN;
        response[1] = RSP_OK;
        response[2] = request[RQS_MAPPER_PID];
        pthread_mutex_lock(&updateTable_lock);
        addEntry(request[RQS_MAPPER_PID]);
        pthread_mutex_unlock(&updateTable_lock);
        write(tArg->clientfd, (void *) response,sizeof(int)* RESPONSE_MSG_SIZE);
        break;

      case UPDATE_AZLIST:
        pthread_mutex_lock(&azList_lock);
        for (int i = 2; i < 28; i++){azList[i-2] += ntohs(request[i]);}
        pthread_mutex_unlock(&azList_lock);
        response[0] = UPDATE_AZLIST;
        response[1] = RSP_OK;
        response[2] = request[RQS_MAPPER_PID];
        //pthread_mutex_lock(&updateTable_lock);
        if (incrementStatus(request[RQS_MAPPER_PID]) == -1){
          response[1] = RSP_NOK;
        }
        //pthread_mutex_unlock(&updateTable_lock);
        write(tArg->clientfd, (void *) response,sizeof(int)* RESPONSE_MSG_SIZE);
        break;

      case GET_AZLIST:
        printf("[%d] GET_AZLIST\n", request[RQS_MAPPER_PID]);
        int long_response[LONG_RESPONSE_MSG_SIZE];
        long_response[0] = GET_AZLIST;
        long_response[1] = RSP_OK;
        pthread_mutex_lock(&azList_lock);
        for (int i = 2; i < 28; i++){long_response[i] = htons(azList[i-2]);}
        pthread_mutex_unlock(&azList_lock);
        write(tArg->clientfd, (void *) long_response, sizeof(int)*LONG_RESPONSE_MSG_SIZE);
        break;

      case GET_MAPPER_UPDATES:
        printf("[%d] GET_MAPPER_UPDATES\n", request[RQS_MAPPER_PID]);
        response[0] = GET_MAPPER_UPDATES;
        response[1] = RSP_OK;
        response[2] = 0;
        //pthread_mutex_lock(&updateTable_lock);
        for(int i = 0; i < 50; i++){
          if (updateStatusTable[i].id == request[RQS_MAPPER_PID]){
            response[2] = htons(updateStatusTable[i].updates);
          }
        }
        //pthread_mutex_unlock(&updateTable_lock);
        write(tArg->clientfd, (void *) response,sizeof(int)* RESPONSE_MSG_SIZE);
        break;

      case GET_ALL_UPDATES:
        printf("[%d] GET_ALL_UPDATES\n", request[RQS_MAPPER_PID]);
        updates = 0;
        response[0] = GET_ALL_UPDATES;
        response[1] = RSP_OK;
        pthread_mutex_lock(&updateTable_lock);
        for (int i = 0; i < 50; i++){
          if (updateStatusTable[i].id != -2){
            updates += updateStatusTable[i].updates;
          }  // check clientfd for NULL instead?
        }
        pthread_mutex_unlock(&updateTable_lock);
        response[2] = updates;
        write(tArg->clientfd, (void *) response,sizeof(int)* RESPONSE_MSG_SIZE);
        break;


      case CHECKOUT:
        printf("[%d] CHECKOUT\n", request[RQS_MAPPER_PID]);
        response[0] = CHECKOUT;
        response[1] = RSP_OK;
        response[2] = request[RQS_MAPPER_PID];
        pthread_mutex_lock(&updateTable_lock);
        for(int i = 0; i < 50; i++){
          if (updateStatusTable[i].id == request[RQS_MAPPER_PID]){
            updateStatusTable[i].checkflag = 0;
          }
        }
        pthread_mutex_unlock(&updateTable_lock);
        write(tArg->clientfd, (void *) response,sizeof(int)* RESPONSE_MSG_SIZE);
        checkout = 1;
        close(tArg->clientfd);
        printf("[%d] close connection\n", request[RQS_MAPPER_PID]);
        free(tArg);
        pthread_mutex_lock(&currentConn_lock);
        currentConn--;
        pthread_mutex_unlock(&currentConn_lock);
        break;
      default:
        //printf("Invalid command: %d from %d\n", request[0],request[1]);
        break;
        //NOT VALID RQS_COMMAND_ID
    }
  }
  return NULL;
}


int main(int argc, char *argv[]) {

    int server_port;

    if (argc == 2) { // 1 arguments
        server_port = atoi(argv[1]);
    } else {
        printf("Invalid or less number of arguments provided\n");
        printf("./server <server Port>\n");
        exit(0);
    }


    // start up mutexes and thread array
    pthread_t threads[MAX_CONCURRENT];
    pthread_mutex_init(&currentConn_lock, NULL);
    pthread_mutex_init(&azList_lock, NULL);
    pthread_mutex_init(&updateTable_lock, NULL);

    int sock = socket(AF_INET , SOCK_STREAM , 0);

  	// Bind it to a local address.
  	struct sockaddr_in servAddress;
  	servAddress.sin_family = AF_INET;
  	servAddress.sin_port = htons(server_port);
  	servAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  	bind(sock, (struct sockaddr *) &servAddress, sizeof(servAddress));


  	// We must now listen on this port.
  	listen(sock, MAX_CONCURRENT);
    printf("server is listening\n");


    int currentConn = 0;
    for (int i = 0; i < 26; i++){azList[i] = 0;}
    for(int i = 0; i < 50; i++){updateStatusTable[i].id = -2;}


    // Server (Reducer) code
    while(1){
      struct sockaddr_in clientAddress;
      socklen_t size = sizeof(struct sockaddr_in);
  		int clientfd = accept(sock, (struct sockaddr*) &clientAddress, &size);

      struct threadArg *arg = (struct threadArg *) malloc(sizeof(struct threadArg));

      arg->clientfd = clientfd;
      arg->clientip = inet_ntoa(clientAddress.sin_addr);
      arg->clientport = clientAddress.sin_port;
      printf("open connection from %s:%d\n",arg->clientip,arg->clientport);

      // check if < 50 current connections and start thread if not
      if (currentConn < MAX_CONCURRENT && clientfd != -1){
        pthread_mutex_lock(&currentConn_lock);
        // separate ccCursor so currentConn isn't updated between being unlocked
        // and thread being created
        int ccCursor = currentConn;
        currentConn++;
        pthread_mutex_unlock(&currentConn_lock);
        pthread_create(&threads[ccCursor],NULL,reducer, (void*) arg);
        }
    }
    return 0;
}
