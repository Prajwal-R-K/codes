#include <stdio.h>

// Define the maximum number of terms
#define MAX_TERMS 100

// Define the polynomial structure
typedef struct polynomial
{
    float coef;
    int expon;
} polynomial;

// Arrays to store polynomial terms
polynomial termsA[MAX_TERMS];
polynomial termsB[MAX_TERMS];
polynomial result[MAX_TERMS * 2]; // The maximum degree of the sum is the sum of the maximum degrees of the two polynomials

// Variable to keep track of the available position in the result array
int availResult = 0;

// Function to input coefficients and exponents of a polynomial term
void inputTerm(polynomial *term)
{
    printf("Enter coefficient: ");
    scanf("%f", &(term->coef));

    printf("Enter exponent: ");
    scanf("%d", &(term->expon));
}

// Function to add a term to the polynomial
void addTerm(polynomial *poly, float coef, int expon)
{
    if (availResult < MAX_TERMS*2)
    {
        poly[availResult].coef = coef;
        poly[availResult].expon = expon;
        availResult++;
    }
    else
    {
        printf("Error: Polynomial is full. Cannot add more terms.\n");
    }
}

// Function to display the polynomial
void displayPolynomial(polynomial *poly, int numTerms)
{
    printf("Polynomial: ");
    for (int i = 0; i < numTerms; i++)
    {
        printf("%.2fx^%d", poly[i].coef, poly[i].expon);
        if (i < numTerms - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
void addPolynomials(polynomial *polyA, int numTermsA,polynomial *polyB, int numTermsB, polynomial *result)
{
    int i = 0, j = 0;

    while (i < numTermsA && j < numTermsB)
    {
        if (polyA[i].expon > polyB[j].expon)
        {
            addTerm(result, polyA[i].coef, polyA[i].expon);
            i++;
        }
        else if (polyA[i].expon < polyB[j].expon)
        {
            addTerm(result, polyB[j].coef, polyB[j].expon);
            j++;
        }
        else
        {
            // The exponents are equal, add the coefficients
            addTerm(result, polyA[i].coef + polyB[j].coef, polyA[i].expon);
            i++;
            j++;
        }
    }

    // Add remaining terms from both polynomials (if any)
    while (i < numTermsA)
    {
        addTerm(result, polyA[i].coef, polyA[i].expon);
        i++;
    }

    while (j < numTermsB)
    {
        addTerm(result, polyB[j].coef, polyB[j].expon);
        j++;
    }
}

int main()
{
    /*
        polynomial termsA[MAX_TERMS];
        polynomial termsB[MAX_TERMS];
        polynomial result[MAX_TERMS * 2]; 
    */
    int numTermsA, numTermsB;

    // Input the number of terms for the first polynomial
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &numTermsA);

    // Input coefficients and exponents for each term of the first polynomial
    for (int i = 0; i < numTermsA; i++)
    {
        printf("Enter details for term %d of the first polynomial:\n", i + 1);
        inputTerm(&termsA[i]);
    }

    // Display the first polynomial
    printf("First ");
    displayPolynomial(termsA, numTermsA);

    // Input the number of terms for the second polynomial
    printf("\nEnter the number of terms for the second polynomial: ");
    scanf("%d", &numTermsB);

    // Input coefficients and exponents for each term of the second polynomial
    for (int i = 0; i < numTermsB; i++)
    {
        printf("Enter details for term %d of the second polynomial:\n", i + 1);
        inputTerm(&termsB[i]);
    }

    // Display the second polynomial
    printf("Second ");
    displayPolynomial(termsB, numTermsB);

    // Add the two polynomials
    addPolynomials(termsA, numTermsA, termsB, numTermsB, result);

    // Display the sum of the polynomials
    printf("\nSum of the two polynomials: ");
    displayPolynomial(result, availResult);

    return 0;
}
