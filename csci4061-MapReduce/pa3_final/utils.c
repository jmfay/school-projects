/*test machine: CSELAB_machine_name * date: mm/dd/yy
* name: full_name1 , [full_name2]
* x500: id_for_first_name , [id_for_second_name] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
// pthread.h included in header.h

// implement shared queue, final histogram here..

struct Queue;

// initalize Queue
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->head = q->tail = NULL;
    return q;
}

// return string data from front of queue
char* peek(struct Queue* q){
  if (q->head == NULL){
    return NULL;
  }
  return q->head->data;

}

//just deletes head because can't return actual node without memory errors
void dequeue(struct Queue* q){
  if (q->head == NULL){
    return;
  }
  //printf("HEAD: %s", q->head->data);
  struct Node *temp = q->head;
  q->head = q->head->next;
  free(temp->data);
  free(temp);

  return;
}

// take line string and create new node and place at end of queue
int enqueue(struct Queue* q, char* line){
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = line;
  newNode->line_num = line_counter;
  newNode->next = NULL;

  if (q->head == NULL){
    q->head = newNode;
    q->tail = newNode;
    return 0;
  }
  q->tail->next = newNode;
  q->tail = newNode;
  return 0;
}

// return line number of package at front of queue, used by consumers
int GetHeadNum(struct Queue* q){
  return q->head->line_num;
}

// appropiately frees all memory
void deleteQueue(struct Queue* q){
  while(q->head != NULL){
    dequeue(q);
  }
  free(q);
  return;
}

int isEmpty(struct Queue* q){
  return q->head == NULL;
}
