#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30, d = 40, e = 50;

    // Array of 5 pointers to integers
    int *plist[5];

    // Assigning addresses of integer variables to array elements
    plist[0] = &a;
    plist[1] = &b;
    plist[2] = &c;
    plist[3] = &d;
    plist[4] = &e;

    // Accessing and printing values using the pointers
    for (int i = 0; i < 5; i++) {
        printf("Value at plist[%d]: %d\n", i, *plist[i]);
    }

    return 0;
}
