// Add Guard to header file
// Function prototype for
//			reduce function that will receive list from all the Mappers to create a single list
//			the single list is then written to ReducerResult.txt

#ifndef PHASE3_H
#define PHASE3_H

#include"../include/main.h"
// for tuple struct
#include "../include/phase2.h"

  void phase3(int mappers, int fds[mappers][2]);


#endif
