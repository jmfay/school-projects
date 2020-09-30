/*test machine: CSELAB_machine_name * date: mm/dd/yy
* name: full_name1 , [full_name2]
* x500: id_for_first_name , [id_for_second_name] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include <ctype.h>
// pthread.h included in header.h

// thread's consumer id passed in
void * consumer(void* arg){
  // random delay
  usleep(rand() % 1000);

  int *consumer_id = (int*) arg;
  FILE* logPtr;

  //prepare to write to log.txt
  if (PFLAG){
    logPtr = fopen("log.txt","a");
    if (!logPtr){
      printf("Error creating log.txt\n");
      PFLAG = 0;
    }
    else{
      fprintf(logPtr,"consumer %d\n", consumer_id);
      fclose(logPtr);
    }
  }

  // continue until eof notification from consumer AND buffer empty
  while(1){
    usleep(rand() % 10000);
    // LOCK QUEUE, ACCESSING Q
    if(eof==-1 && isEmpty(q)){
      break;
    }
    if(!isEmpty(q)){
      char line[1024];

      // SHARED RESOURCES, LOCK HERE
      if (BFLAG) {
        sem_wait(&full_count);
      }
      sem_wait(&q_mutex);

      // copy string data from package at front of buffer queue
      strcpy(line, peek(q));

      // print consumer id and line it retrieved if -p used
      if (PFLAG){
        logPtr = fopen("log.txt", "a");
        fprintf(logPtr,"consumer %d: %d\n", consumer_id, GetHeadNum(q));
        fclose(logPtr);
      }

      // remove package at front of queue
      dequeue(q);
      //printf("Consumer line retrieved by %d: %s", consumer_id, line);

      // DONE WITH SHARED RESOURCES, UNLOCK HERE
      if (BFLAG) {
        sem_post(&empty_count);
      }
      sem_post(&q_mutex);


    // begin to search line string for alphabet characters that occur after
    // non-alphabetic characters
    for(int i = 0; i < strlen(line); i++){

      // special case to check first character in line
      if (i == 0 && isalpha(line[0])){
        char c = tolower(line[0]);

        // LOCK HISTOGRAM
        sem_wait(&hist_mutex);
        histogram[((int)c)-97].count++;
        //UNLOCK HISTOGRAM
        sem_post(&hist_mutex);
      }

      // check if non-alphabetic character's successor is alphabetic, add to
      // histogram if it is
      else if(!isalpha(line[i])){
        if (i+1 < strlen(line) && isalpha(line[i+1])){
          char c = tolower(line[i+1]);
          //LOCK HISTOGRAM
          sem_wait(&hist_mutex);
          histogram[((int)c)-97].count++;
          //UNLOCK HISTOGRAM
          sem_post(&hist_mutex);
        }
      }
    }
  }
 }
}
