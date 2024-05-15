#include <stdio.h>

void Hanoi(int n, char x, char y, char z)
{
    if (n > 1)
    {
        Hanoi(n-1,x,z,y);
        printf("Move disk %d from %c to %c.\n",n,x,z); 
        Hanoi(n-1,y,x,z);
    }
    else
    {
        printf("Move disk %d from %c to %c.\n",n,x,z);
    }
}

int main() {
    int num_disks;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks <= 0)
    {
        printf("Number of disks should be greater than 0.\n");
        return 1;
    }

    // Call the Hanoi function to solve the Tower of Hanoi problem
    Hanoi(num_disks, 'A', 'B', 'C');

    return 0;
}
