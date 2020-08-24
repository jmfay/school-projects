#include "../include/phase1.h"

// You are free to use your own logic. The following points are just for getting started
/* 	Data Partitioning Phase - Only Master process involved
	1) 	Create 'MapperInput' folder
	2) 	Traverse the 'Sample' folder hierarchy and insert the text file paths
		to Mapper_i.txt in a load balanced manner
	3) 	Ensure to keep track of the number of text files for empty folder condition

*/
extern int errno;

int findFiles(char* cd, char** mapFiles, int mappers, int fileCount){
  //open folder path and check for error doing so
  DIR *dr = opendir(cd);
  if (dr == NULL){
    printf("Could not open directory: %s: %s\n", cd, strerror(errno));
    return -1;
  }

  struct stat filestat;
  FILE * fPtr;
  struct dirent * de;
  while ((de = readdir(dr)) != NULL){
		// ignore . and ..
		if (!strncmp(de->d_name,"..",2) || !strncmp(de->d_name,".",2)){
			continue;
		}

    // EXTRA CREDIT (37-47)
    //if a file is found to be a symbolic link, skip it to avoid reprocessing
    char cwd[1024] = "";
    strcat(cwd,cd);
    strcat(cwd,"/");
    strcat(cwd,de->d_name);
    lstat(cwd, &filestat);
    if (S_ISLNK(filestat.st_mode)){
      //printf("LINK! %s\n", cwd);
      continue;
    }

		// check if directory entry is folder and recurse in, returning updating
    // file count
		if (de->d_type == DT_DIR){
        // build proper path name for subdirectory
        int subCount = findFiles(cwd, mapFiles,mappers, fileCount);
        // add files counted in recursive call to current call
        if (subCount != -1){
          fileCount = subCount;
        }
		}

    // enters else body directory entry (de) is a file
    else{
      //build full file path to be placed in proper mapper_x.txt file
      char cwd[1024];
      getcwd(cwd,sizeof(cwd));
      strcat(cwd,"/");
      strcat(cwd,cd);
      strcat(cwd,"/");
      strcat(cwd,de->d_name);

      fPtr = fopen(mapFiles[fileCount % mappers], "a");

      strcat(cwd,"\n");
      fputs(cwd,fPtr);
      fclose(fPtr);
      fileCount++;
    }
  }
  closedir(dr);
  return fileCount;
}



int phase1(char* path, int mappers){
  // creation of MapperInput directory, check for error creating
  char* dirname = "MapperInput";
  //errno 17 is error returned when directory is already made
  if(mkdir(dirname, 0777) && errno != 17){
    printf("Unable to create directory %s\n", strerror(errno));
    return -1;
  }

  //place empty Mapper_i.txt files in MapperInput folder
  char *mapFiles[mappers];
  char *temp;
  for (int i = 0; i < mappers; i++){
    temp = malloc(22);
    strcpy(temp,"");
    strcpy(temp,dirname);
    strcat(temp,"/");
    char buffer[3];
    char map[10] = "Mapper_";
    sprintf(buffer, "%d", i);
    strcat(map, buffer);
    strcat(temp,map);
    mapFiles[i] = (char*)temp;
  }


  // begin recursive search for files in root directory passed
  // in on command line
  int fileCount = findFiles(path,mapFiles,mappers,0);

  // free mapFile pointers, no longer needed
  for(int i = 0; i < mappers;i++){
    free(mapFiles[i]);
  }

  // error returned by findFiles
  if (fileCount < 0){
    return -1;
  }

  // no files in root folder passed in
  if (fileCount == 0){
    printf("The folder %s is empty\n", path);
    return 0;
  }
  return fileCount;
}
