// Add Guard to header file
// Function prototypes for
//			map function that will go through text files in the Mapper_i.txt to get the (letter, wordcount)

#ifndef PHASE2_H
#define PHASE2_H

#include"../include/main.h"

typedef struct{
  char letter;
  int count;
} tuple;


void map(char* path, tuple tArray[]);
void phase2(int* fd, int mapper_num);

#endif
