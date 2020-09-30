#include "../include/phase2.h"
// You are free to use your own logic. The following points are just for getting started
/* 	Map Function
	1)	Each mapper selects a Mapper_i.txt to work with
	2)	Creates a list of letter, wordcount from the text files found in the Mapper_i.txt
	3)	Send the list to Reducer via pipes with proper closing of ends
*/

void map(char* path, tuple tArray[]){
  FILE* txtPtr;
  if ((txtPtr = fopen(path,"r")) == NULL){
    printf("Error reading text file\n");
    return;
  }
  else{
    // max line size
    char line[256];
    // iterate line by line in file
    while(fgets(line,sizeof(line),txtPtr)){
      // 97 is ASCII code for 'a', so take int value of c retrieved
      // and increment correct letter in tArray
      char c = tolower(line[0]);
      tArray[((int)c) - 97].count++;
    }

  }
  return;
}



void phase2(int* fd, int mapper_num){

  // build tuple array, for each letter of alphabet and initialize count to 0
  tuple tupleArray[26];
  char c;
  for (int i = 97; i < 123; i++){
    char c = i;
    tupleArray[i-97].letter = c;
    tupleArray[i-97].count = 0;
  }
  close(fd[0]);
  char cwd[1024];
  getcwd(cwd,sizeof(cwd));
  strcat(cwd,"/MapperInput/");

  // go to appropiate /MapperInput/Mapper_i file that was designated to process
  // running this instance of phase2
  char number[3];
  sprintf(number, "%d", mapper_num);
  strcat(cwd,"Mapper_");
  strcat(cwd,number);

  FILE* fPtr;
  if ((fPtr = fopen(cwd, "r")) == NULL){
    printf("Error reading file: %s\n", cwd);
    return;
  }

  // retrieve a file path from Mapper_i file and run map, until all file paths
  // have been processed
  char newpath[1024];
  while(fgets(newpath,sizeof(newpath),fPtr)){
    strtok(newpath,"\n");
    map(newpath,tupleArray);
  }

  // create buffer storing values of tupleArray (letter and count), and send
  // through the pipe passed into phase2
  char buff[32];
  // 32 arbitrary buffer size, 26 is # of letters in alphabet
  char final_buff[32*26] = "";
  for(int i = 0; i < 26; i++){
    sprintf(buff,"<%c, %d>\n", tupleArray[i].letter, tupleArray[i].count);
    strcat(final_buff, buff);
  }
  write(fd[1], final_buff, (strlen(final_buff)+1));
  close(fd[1]);
  fclose(fPtr);
  }
