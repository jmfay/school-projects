/*test machine: CSELAB_machine_name * date: mm/dd/yy
* name: full_name1 , [full_name2]
* x500: id_for_first_name , [id_for_second_name] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
// pthread.h included in header.h
int MAX_LINE_SIZE = 1024;

// fPtr being passed in
void * producer(void* arg){
  // random delay and creation of file pointers, logPtr optional for -p flag
  usleep(rand() % 1000);
  FILE* logPtr;
  FILE* fPtr = (FILE*) arg;


  //begin log.txt file if indicated in command line
  if (PFLAG){
    logPtr = fopen("log.txt","w");
    if (!logPtr){
      printf("Error creating log.txt\n");
      PFLAG = 0;
    }
    else{
      fprintf(logPtr,"producer\n");
      fclose(logPtr);
    }
  }

  // line counter to be passed in queue so consumers know what line they have
  line_counter = 0;
  char* line;
  // while not at end of file
  while(!feof(fPtr)){

    //prepare new line to be read/ return if at end
    char *line = malloc(1024*sizeof(char*));

    // prevents random blank line being put into buffer
    if (!fgets(line,1024,fPtr)){
      eof = -1;
      return NULL;
    }
    //SHARED RESOURCES... LOCK HERE
    if (BFLAG) {
      sem_wait(&empty_count);
    }
    sem_wait(&q_mutex);
    if (PFLAG){
      logPtr = fopen("log.txt", "a");
      fprintf(logPtr,"producer %d\n", line_counter);
      fclose(logPtr);
    }
    // add line to queue, line counter is global but will be included in package
    enqueue(q, line);
    line_counter++;
    //printf("ADDED: %s", line);
    //DONE WITH SHARED RESOURCE, UNLOCK HERE
    sem_post(&q_mutex);
    if (BFLAG) {
      sem_post(&full_count);
    }
  }
  eof = -1;
}
