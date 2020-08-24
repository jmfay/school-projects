/* test machine : CSE LAB_ machine_name
* date : mm / dd / yy
* name : full_name1 , [full_name2]
* x500 : id_for_first_name , [id_for_second_name]
*/


• The purpose of your program

    The purpose of the program is to imitate mapReduce algorithm functionality. The command line arguments passed in are the folder to search for txt files, and the number of child processes to divide up the files and map them. These processe then send data through pipes back to the parent process, which delegates a new process with these pipes to combine into a text file. This text file is then rewritten to FinalInput.txt

• How to compile the program

USED TEMPLATE MAKE FILE
    To compile, first run 'make clean' from the src/ folder to ensure any files/folders left over from previous tests are cleared out. Then, use 'make mapreduce' to create an executable called 'mapreduce', which takes the command line arguments when run in terminal.

• What exactly your program does

PHASE 1:
    The program begins by taking the command line arguments and records how many mappers were requested in the command line. The program then enters phase1, where it creates Mapper_i.txt files in the MapperInput folder. Then, it takes the path provided in the terminal to begin a recursive search through the directory using the dirent struct to locate folders to recurse into, symbolic links (using lstat & stat struct), and individual files. The individual file paths are computed and written to/distributed evenly among the number of Mapper_i.txt files

PHASE 2:
    Main.c then creates i pipes, one for each mapper, in an array and begins to spawn child processes to take a pipe and integer indicating what Mapper_i.txt file to work with, and begins to access the files via the file paths in the text file, mapping the first letter of each line to a list of tuple structs, which contain each letter of the alphabet and # of occurrences for that letter. A child process will add occurrences of each letter for each file described in the Mapper_i.txt file, and then write the final total of each letter into the pipe passed into phase2.

PHASE 3:
    Back in main, the master process waits for each child mapper process to finish before spawning a new child process to enter phase3, where the list of the pipes is passed in and the process creates a new tuple list for each letter again, and reads each pipe from each mapper and adds the occurrences of each letter to this new master tuple list. Then, the process uses master tuple list to report the total occurrences of each letter, for all the files processed, into a text file called 'ReducerResult.txt'.

PHASE 4:
    Before phase4, the master process waits for the child process to finish phase3. Then, the master process enters into phase4, where it takes the results entered into 'ReducerResult.txt' and places them into a file called 'FinalResult.txt'.

• Any assumptions outside this document

    The assumptions made are that the text files being scanned contain one word per line, with no whitespace/special characters before the first letter of each line.

• Team names and x500

    Worked alone, fayxx092

• Your and your partners individual contributions

• If you have attempted extra credit

    Yes, source code for it can be found in phase1.c, lines 32-40
