/*test machine: CSELAB_machine_name * date: mm/dd/yy
* name: full_name1 , [full_name2]
* x500: id_for_first_name , [id_for_second_name] */

/*
header.h, header for all source files
it will:
- structure definition
- global variable, lock declaration (extern)
- function declarations
*/
#ifndef _HEADER_H_
#define _HEADER_H_
  #include <semaphore.h>
  #include <pthread.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <unistd.h>
  //#include "utils.c"
  int eof, line_counter;
  int PFLAG;
  int BFLAG;
  int consumer_count, buffer_size;
  sem_t q_mutex, empty_count, full_count;
  sem_t hist_mutex;

  typedef struct{
    char letter;
    int count;
  } tuple;

  tuple histogram[26];

  struct Node {
    char *data;
    int line_num;
    struct Node *next;
  };

  struct Queue {
    struct Node *head, *tail;
  };

  struct Queue* q;

  void * producer(void * arg);

  void * consumer(void * arg);

  int enqueue(struct Queue *q, char* line);
  struct Queue* createQueue();

  char* peek(struct Queue* q);
  void dequeue(struct Queue* q);

  int GetHeadNum();

  int enqueue(struct Queue* q, char* line);

  void deleteQueue(struct Queue* q);

  int isEmpty(struct Queue* q);
// header here..






#endif
