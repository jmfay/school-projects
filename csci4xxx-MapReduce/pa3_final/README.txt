/* test machine : CSE LAB_ machine_name
* date : mm / dd / yy
* name : full_name1 , [full_name2]
* x500 : id_for_first_name , [id_for_second_name]
*/


• The purpose of your program

    The purpose of the program is to scan an input file and return a file containing a histogram of the count of each letter that a word starts with in the input file. The program utilizes semaphores and multithread to accomplish this in a time-effiient way.

• How to compile the program

USED TEMPLATE MAKE FILE
    To compile, first run 'make clean' from the src/ folder to ensure any files/folders left over from previous tests are cleared out. Then, use 'make' to create an executable called 'wcs', which takes the command line arguments when run in terminal.

• What exactly your program does

MAIN
    The program begins by taking in the command line arguments, figuring out the number of consumers to be made, the input file (and if valid), as well as optional flags -b,-bp,-p and any additional arguments needed. The program then initializes the semaphores needed for safe multithreading with global resources, and first creates the producer thread. The program then creates n number of consumers and creates a thread and id # for each. The main thread then waits for all producers and consumers to finish before attempting to write the finalized histogram of letter occurrences into result.txt. The main thread then destroys any semaphores used and frees dynamically allocated memory.

PRODUCER
    The producer thread takes in the file pointer created in main and begins to go line by line, storing a line as a string in a variable to be placed in a package along with the line number, and then sent off into the queue using enqueue(). The producer locks/unlocks the shared queue while doing this, and will terminate once the end of the file is reached and sends a notification (in this project, a global variable) to notify the consumers that there will be no more new packages.

CONSUMER
    The consumer threads take in their id # created by main, used in -p flag, and enter into an infinite loop to retrieve packages from the queue (which it locks and unlocks while doing so). It takes the string representing a line in the input file, and the line # of that line (used for -p). The consumers will break from the infinite loop once the eof notification is received AND there are no more packages in the queue. While consuming packages, the consumer threads will take the string data and begin to search for nonalphabetic characters. Each time a non-alphabetic character is found, the consumer checks the character right after it to see if that is a alphabetic character, and if it is, it is added to the histogram (using semaphore locks to ensure synchronization).

//UTILS
    Utils.c contains the necessary methods to operate on the linked list queue.

• Any assumptions outside this document

    No outside assumptions made

• Team names and x500

    Worked alone, fayxx092

• Your and your partners individual contributions

• If you have attempted extra credit

    Yes, BFLAG is an optional portion of the program, allowing you to bound the buffer to a certain size by using additional semaphores.
