#include<stdio.h>
int main()
{
 // Assume 4x5 sparse matrix
 int sparseMatrix[4][5] =
 {
 {0 , 0 , 3 , 0 , 4 },
 {0 , 0 , 5 , 7 , 0 },
 {0 , 0 , 0 , 0 , 0 },
 {0 , 2 , 6 , 0 , 0 }
 };

 int size = 0;
 for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++)
        if (sparseMatrix[i][j] != 0)
            size++;     // Calulating how many elements are not Zero

 // Making of new matrix
 int compactMatrix[3][size];
 int k = 0;
 for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++)
        if (sparseMatrix[i][j] != 0)
        {
            compactMatrix[0][k] = i;
            compactMatrix[1][k] = j;
            compactMatrix[2][k] = sparseMatrix[i][j];
            k++;
        }
 
    //Display
    // 1st row represents Which row of Orginal Matrix
    // 2nd row represents Which coloum of Original Matrix
    // 3rd row represents the value of Original Matrix
 for (int i=0; i<3; i++)
 {
    for (int j=0; j<size; j++)
         printf("%d ", compactMatrix[i][j]);
    printf("\n");
 }
 return 0;
}
