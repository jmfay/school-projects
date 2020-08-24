/*test machine: CSELAB_machine_name * date: mm/dd/yy
* name: full_name1 , [full_name2]
* x500: id_for_first_name , [id_for_second_name] */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
//#include <zconf.h>
#include <arpa/inet.h>
#include <ctype.h>
#include "../include/protocol.h"

FILE *logfp;

void createLogFile(void) {
    pid_t p = fork();
    if (p==0)
        execl("/bin/rm", "rm", "-rf", "log", NULL);

    wait(NULL);
    mkdir("log", 0777);
    logfp = fopen("log/log_client.txt", "w");
}

int main(int argc, char *argv[]) {
    int mappers;
    char folderName[100] = {'\0'};
    char *server_ip;
    int server_port;

    if (argc == 5) { // 4 arguments
        strcpy(folderName, argv[1]);
        mappers = atoi(argv[2]);
        server_ip = argv[3];
        server_port = atoi(argv[4]);
        if (mappers > MAX_MAPPER_PER_MASTER) {
            printf("Maximum number of mappers is %d.\n", MAX_MAPPER_PER_MASTER);
            printf("./client <Folder Name> <# of mappers> <server IP> <server Port>\n");
            exit(1);
        }

    } else {
        printf("Invalid or less number of arguments provided\n");
        printf("./client <Folder Name> <# of mappers> <server IP> <server Port>\n");
        exit(1);
    }

    // create log file
    createLogFile();
    fclose(logfp);
    // too many mapper clients provided, set down to limit of 32.
    if (mappers > 32){
      mappers = 32;
    }
    // phase1 - File Path Partitioning
    traverseFS(mappers, folderName);

    pid_t pid,wpid;
    int status = 0;
    // Phase2 - Mapper Clients's Deterministic Request Handling

    // begin forking for individual mapper processes
    for (int id = 1; id <= mappers; id++){
      pid = fork();
  		if (pid == -1){
  			printf("Error creating child process for phase2\n");
  			return -1;
  		}
  	  else if (pid == 0){
  			// child process enters phase2 with server info and id to access
  			// specific mapper_id file in MapperInput
  			phase2(id, server_ip, server_port);
  			exit(0);
      }
    }

    // wait for mapper processes to finish
    while((wpid = wait(&status)) > 0);
    // Phase3 - Master Client's Dynamic Request Handling (Extra Credit)
    return 0;
}
