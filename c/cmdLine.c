#include <stdio.h>

int main(int argc, char *argv[]) {

    //argc (argument count) holds the number of command-line arguments.
    // argv (argument vector) is an array of strings (char*) that contains the actual command-line arguments.
    
    printf("Number of command-line arguments: %d\n", argc);

    // Print each command-line argument
    // The first element (argv[0]) is the name of the program, 
    //and subsequent elements contain the actual command-line arguments.
    for (int i =0; i <argc; i++) {             // or To make in reverse order--        for (int i = argc-1; i >0-1; i--)
        printf("Argument %d: %s\n", i, argv[i]); 
         // or printf("Argument %d: %s\n", i, *argv++);
    }

    return 0;
}
//example
//compile -- // gcc cmdLine.c                or                 cd "c:\Users\Administrator\Desktop\codes\c\" ; if ($?) { gcc cmdLine.c -o cmdLine } ; if ($?) { .\cmdLine 5 2 3 4 1 } 
//run -- // .\cmdLine 6 1 2 3 4 5 6
//6 1 2 3 4 5 6---These are all strings not integer to access them use string format specifiers(%s).