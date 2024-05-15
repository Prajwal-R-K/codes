#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct term
{
    int col;
    int row;
    int value;
} term;

void inputSparseMatrix(term a[]); // Take input from the users
void displaySparseMatrix(term a[]); // Display the sparse matrix
void transpose(term a[], term b[]);  // Transpose the sparse matrix
void mmult(term a[], term b[], term d[]); // multiply the two sparse matrix
void storesum(term d[], int *totald, int row, int column, int *sum); // Used to store result obtained from mmult() function
void addSparseMatrices(term a[], term b[], term result[]);  // Add two sparse Matrix

int main()
{
    term a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS], result[MAX_TERMS];

    printf("Input for Matrix A:\n");
    inputSparseMatrix(a);
    printf("\nMatrix A:\n");
    displaySparseMatrix(a);

    transpose(a, b);
    printf("\nTranspose of Matrix A (Matrix B):\n");
    displaySparseMatrix(b);

    printf("\nInput for Matrix B:\n");
    inputSparseMatrix(c);
    printf("\nMatrix B:\n");
    displaySparseMatrix(c);

    // Adding two sparse matrices
    addSparseMatrices(a, b, result);
    printf("\nAddition Result (Matrix D = A + B):\n"); //result=a+c
    displaySparseMatrix(result);

    mmult(a, c, result);
    printf("\nMultiplication Result (Matrix C = A * B):\n");// result=a*c
    displaySparseMatrix(result);


    return 0;
}


void addSparseMatrices(term a[], term b[], term result[])
{
    int i = 1, j = 1, k = 1;
    while (i <= a[0].value && j <= b[0].value)
    {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col))
        {
            result[k] = a[i];
            i++;
        }
        else if (a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col))
        {
            result[k] = b[j];
            j++;
        }
        else
        {
            result[k] = a[i];
            result[k].value += b[j].value;
            i++;
            j++;
        }
        k++;
    }

    while (i <= a[0].value)
    {
        result[k++] = a[i++];
    }

    while (j <= b[0].value)
    {
        result[k++] = b[j++];
    }

    result[0].row = a[0].row;
    result[0].col = a[0].col;
    result[0].value = k - 1;
}


void inputSparseMatrix(term a[])
{
    int rows, cols, numTerms;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    a[0].row = rows;
    a[0].col = cols;


    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numTerms);

    printf("Enter the non-zero elements (row, column, value):\n");

    for (int i = 1; i <= numTerms; i++)
    {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    a[0].value = numTerms;
}

void displaySparseMatrix(term a[])
{
    printf("Sparse Matrix:\n");
    printf("Row\tColumn\tValue\n");

    for (int i = 0; i <= a[0].value; i++)
    {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    }
}

void transpose(term a[], term b[])
{
    int n, i, j, currentb;
    n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    if (n > 0)
    {
        currentb = 1;
        for (i = 0; i < a[0].col; i++)
            for (j = 1; j <= n; j++)
                if (a[j].col == i)
                {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
    }
}


void mmult(term a[], term b[], term d[])
{
    int i, j, column, totalb = b[0].value, totald = 0;
    int rows_a = a[0].row, cols_a = a[0].col, totala = a[0].value;
    int cols_b = b[0].col;
    int row_begin = 1, row = a[1].row, sum = 0;
    term new_b[MAX_TERMS];

    if (cols_a != b[0].row)
    {
        printf("Incompatible matrices\n");
        return;
    }

    a[totala + 1].row = rows_a;
    new_b[totalb + 1].row = cols_b;
    new_b[totalb + 1].col = 0;

    for (i = 1; i <= totala;)
    {
        column = new_b[1].row;
        for (j = 1; j <= totalb + 1;)
        {
            if (a[i].row != row)
            {
                storesum(d, &totald, row, column, &sum);
                i = row_begin;
                for (; new_b[j].row == column; j++)
                    ;
                column = new_b[j].row;
            }
            else
            {
                switch (a[i].col - new_b[j].col)
                {
                case -1:
                    i++;
                    break;
                case 0:
                    sum += (a[i++].value * new_b[j++].value);
                    break;
                case 1:
                    j++;
                    break;
                }
            }
        }
        for (; a[i].row == row; i++)
            ;
        row_begin = i;
        row = a[i].row;
    }

    d[0].row = rows_a;
    d[0].col = cols_b;
    d[0].value = totald;
}



void storesum(term d[], int *totald, int row, int column, int *sum)
{
    // If the result of the multiplication (sum) is not zero
    if (*sum != 0)
    {
        // Check if there is enough space in the result array (d)
        if (*totald < MAX_TERMS)
        {
            // Increment the total number of non-zero terms in the result
            // and store the current result (row, column, value) in the result array
            d[++(*totald)].row = row;
            d[*totald].col = column;
            d[*totald].value = *sum;
        }
        else
        {
            // If the result array is full, print an error message and exit the program
            printf("Number of terms in product exceeds %d\n", MAX_TERMS);
            exit(1);
        }
    }
}
