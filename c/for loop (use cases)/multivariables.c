#include <stdio.h>

int main() {
    // Using multiple variables in the for loop
    for (int i = 1, j = 10   ;   i <= 5   ;   i++, j -= 2)
     {
        //The initialization statement is executed only once.  i.e---    int i = 1, j = 10
       // However, if the test expression is evaluated to true, statements inside the body of the for loop are executed, and the update expression is updated.
        //Again the test expression is evaluated.
        //This process goes on until the test expression is false. When the test expression(condition) is false, the loop terminates.
        printf("i: %d, j: %d\n", i, j);
    }

    return 0;
}
