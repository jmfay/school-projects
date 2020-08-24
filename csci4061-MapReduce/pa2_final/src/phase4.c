#include "../include/phase4.h"
// You are free to use your own logic. The following points are just for getting started
/* Final Result
	1)	The master process reads the "ReducerResult.txt"
	2) 	Print the contents to standard output which is redirected to "FinalResult.txt"
			i.e., on using printf, the statement should be written to "FinalResult.txt"
*/

void phase4(){

  // get full file path
  char cwd[1024];
  getcwd(cwd,sizeof(cwd));
  char cwd2[1024];
  strcpy(cwd2, cwd);

  strcat(cwd,"/ReducerResult.txt");
  strcat(cwd2,"/FinalResult.txt");

  // open ReducerResult.txt
  FILE* fPtr = fopen(cwd,"r");

  if(fPtr == NULL){
   printf("Error opening %s\n", cwd);
   return;
  }

  // prepare to write to FinalResult.txt
  FILE* fPtr2 = fopen(cwd2, "w");
  if(fPtr2 == NULL){
    fclose(fPtr);
    printf("Error opening %s\n", cwd2);
    return;
  }

  char content[256];
  //copy over contents from ReducerResult.txt to FinalResult.txt
  while(fgets(content, sizeof(content),fPtr) != NULL){
    fprintf(fPtr2, "%s", content);
  }
  fclose(fPtr);
  fclose(fPtr2);
  return;
}
