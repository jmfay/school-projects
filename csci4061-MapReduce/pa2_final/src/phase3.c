#include "../include/phase3.h"
// You are free to use your own logic. The following points are just for getting started
/* Reduce Function
	1)	The reducer receives the list from 'm' mappers via pipes
	2)	Ensure proper closing of pipe ends
	3) 	Combine the lists to create a single list
	4) 	Write the list to "ReducerResult.txt" in the current folder
*/

void phase3(int mappers, int fds[mappers][2]){
  // creation of new Tuple struct array to store characters
  // and summed occurrences
  tuple tupleArray[26];
  char c;
  for (int i = 65; i < 91; i++){
    char c = i;
    tupleArray[i-65].letter = c;
    tupleArray[i-65].count = 0;
  }


  // loop to begin to iterate through pipes passed into phase3
  for(int i = 0; i < mappers; i++){
    // read all contents of pipe
    char newbuff[512];
    read(fds[i][0],newbuff,sizeof(newbuff));
    close(fds[i][0]);

    // begin to tokenize long string of pipe contents
    // after tokenizing, single line goes from <a, 25>\n to a\n25\n
    // so, every other line contains # of occurrences for letter
    // lineCount used to decide every other line
    // letter used to track where to put extracted number into tupleArray
    char* line;
    int lineCount = 0;
    int letter = 0;
    line = strtok(newbuff,"<,\n >");
    while(line != NULL){
      if(lineCount % 2 == 1){ //every other line
        const char* num = line;
        tupleArray[letter].count += atoi(num);
        letter++;
      }
      line = strtok(NULL, "<,\n >");
      lineCount++;
    }
  }

  // once done going through pipes and adding occurrences to tupleArray
  // iterate through alphabet tuple array and write in correct format
  // to ReducerResult.txt in current directory
  char cwd[1024];
  getcwd(cwd,sizeof(cwd));
  strcat(cwd,"/ReducerResult.txt");
  FILE* fPtr = fopen(cwd,"w");
  for(int i = 0; i < 26; i++){
    fprintf(fPtr, "%c %d\n", tupleArray[i].letter,tupleArray[i].count);
  }
  fclose(fPtr);

  return;
}
