/* test machine : CSE LAB_ machine_name
* date : mm / dd / yy
* name : full_name1 , [full_name2]
* x500 : id_for_first_name , [id_for_second_name]
*/
#include "../include/main.h"

int main(int argc, char *argv[]){

	// argument count check
	if (argc < 3){
		printf("Invalid input\n");
		return -1;
	}

	//just make a function call to code in phase1.c
	//phase1 - Data Partition Phase
	int mappers = atoi(argv[2]);
	if (mappers < 1 || mappers > 32){
    printf("Invalid number of mappers requested, terminating\n");
    return -1;
  }
	int fileCount = phase1(argv[1],mappers);

	// no files retrieved from phase1 or error returned by phase1
	if (fileCount <= 0 ){
		printf("Error in phase1\n");
		// return 0 to allow makefile test-mapreduce to continue past TestCase1
		return 0;
	}

	// create pipes for n mappers
	int fds[mappers][2];
	for(int i = 0; i < mappers; i++){
		pipe(fds[i]);
	}

	// just make a function call to code in phase2.c
	// phase2 - Map Function
	pid_t pid,wpid;
	int status = 0;
	for (int i = 0; i < mappers; i++){
		pid = fork();
		if (pid == -1){
			printf("Error creating child process for phase2\n");
			return -1;
		}
	  else if (pid == 0){
			// child process enters phase2 with provided pipe and i to access
			// specific mapper_i file in MapperInput
			phase2(fds[i], i);
			exit(0);
		}
	}
	// master will continue once all mappers are done
	while((wpid = wait(&status)) > 0);


	//just make a function call to code in phase3.c
	//phase3 - Reduce Function
	pid = fork();
	if (pid == 0){
		phase3(mappers, fds);
		exit(0);
	}
	// wait for child process to finish phase3
	wait(NULL);

	//phase4
	//wait for all processes to reach this point
	//just make a function call to code in phase4.c
	//master process reports the final output
	phase4();
	return 0;

}
