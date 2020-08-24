/*test machine: CSELAB_machine_name * date: mm/dd/yy
* name: full_name1 , [full_name2]
* x500: id_for_first_name , [id_for_second_name] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
// pthread.h included in header.h


int main(int argc, char const *argv[]) {
  // program executed with not enough arguments
  if (argc < 3){
    printf("Invalid input, need # of consumers and file name.\n");
    return -1;
  }

  // provided enough to establish baseline arguments
  else if (argc >= 3){
    consumer_count = atoi(argv[1]);
    buffer_size = 10;
    BFLAG = 0;
    PFLAG = 0;

    // start to search for flags -b,-p,-bp. Need extra int passed in for -b,-bp
    if (argc > 3){
      if (!strcmp(argv[3],"-p")){
        PFLAG = 1;
      }
      else if (!strcmp(argv[3],"-b")){
        if (argc != 5){
          printf("-b flag used, please provide size of buffer.\n");
          return -1;
        }
        buffer_size = atoi(argv[4]);
        BFLAG = 1;
      }
      else if (!strcmp(argv[3],"-bp")){
        if (argc != 5){
          printf("-bp flag used, please provide size of buffer.\n");
          return -1;
        }
        buffer_size = atoi(argv[4]);
        BFLAG = 1;
        PFLAG = 1;
      }
    }
  }

  // attempt to open file passed in
  FILE *fPtr;
  fPtr = fopen(argv[2], "r");
  if (!fPtr){
    printf("No such file: %s\n", argv[2]);
    return -1;
  }

  // begin declaring semaphores for producers/consumers to use
  // optional buffer semaphore if -b or -bp used in commandline
  sem_init(&q_mutex,0,1);
  if (BFLAG){
    sem_init(&full_count,0,0);
    sem_init(&empty_count,0,buffer_size);
  }

  pthread_t p1;
  pthread_t consumers[consumer_count];
  q = createQueue();

  // start producer
  pthread_create(&p1, NULL, producer, (void *) fPtr);

  //initialize histogram for consumers to modify
  char c;
  for(int i = 97; i < 123; i++){
    char c = i;
    histogram[i-97].letter = c;
    histogram[i-97].count = 0;
  }

  // initialize a mutex for the global histogram and sleep for 1s to allow
  // producer to start filling buffer
  sem_init(&hist_mutex,0,1);
  sleep(1);

  // unleash the consumers
  for(int id = 0; id < consumer_count; id++){
    pthread_create(&consumers[id], NULL, consumer, (void *) id);
  }

  // Wait for all threads to finish
  pthread_join(p1, NULL);
  for (int i = 0; i < consumer_count; i++){
    pthread_join(consumers[i],NULL);
  }
  // close input file since we know producer thread is done now
  fclose(fPtr);

  //master preparing to write contents of histogram into result.txt
  FILE* fPtr2 = fopen("result.txt","w");
  if (!fPtr2){
    printf("Error creating result.txt\n");
    return -1;
  }
  for(int i = 0; i < 26; i++){
    fprintf(fPtr2,"%c: %d\n", histogram[i].letter, histogram[i].count);
  }

  // clean up
  sem_destroy(&q_mutex);
  sem_destroy(&hist_mutex);

  if (BFLAG){
    sem_destroy(&empty_count);
    sem_destroy(&full_count);
  }

  fclose(fPtr2);
  deleteQueue(q);
  return 0;
  }
