#include <stdio.h>
#include <stdlib.h>

// Define the structure of a polynomial Node
typedef struct PolyNode {
    int coef;
    int expon;
    struct PolyNode* link;
} Node;

// Function to create a new polynomial Node
Node* createPolyNode(int coef, int expon) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->coef = coef;
    newNode->expon = expon;
    newNode->link = NULL;
    return newNode;
}

// Function to insert a polynomial term into a polynomial
Node* insertTerm(Node* poly, int coef, int expon) 
{
    Node* temp = poly;
    Node* newnode = createPolyNode(coef, expon);

    if (poly == NULL) 
    {
        return newnode;
    }

    while (temp->link != NULL) 
    {
        temp = temp->link;
    }
    temp->link = newnode;
    return poly;
}

// Function to add two polynomials
Node* addPolynomials(Node* a, Node* b) 
{
    Node* result = NULL;
    Node* tempa = a;
    Node* tempb = b;

    while (tempa != NULL && tempb != NULL) 
    {
        if (tempa->expon == tempb->expon) {
            int sum = tempa->coef + tempb->coef;
            if (sum != 0) 
            {
                result = insertTerm(result, sum, tempa->expon);
            }
            tempa = tempa->link;
            tempb = tempb->link;
        } 
        else if (tempa->expon > tempb->expon) 
        {
            result = insertTerm(result, tempa->coef, tempa->expon);
            tempa = tempa->link;
        } 
        else 
        {
            result = insertTerm(result, tempb->coef, tempb->expon);
            tempb = tempb->link;
        }
    }
    while (tempa != NULL) 
    {
        result = insertTerm(result, tempa->coef, tempa->expon);
        tempa = tempa->link;
    }

    while (tempb != NULL) 
    {
        result = insertTerm(result, tempb->coef, tempb->expon);
        tempb = tempb->link;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(Node* poly) {
    Node* temp = poly;
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (temp != NULL) {
        printf("(%dx^%d) ", temp->coef, temp->expon);
        if (temp->link != NULL) {
            printf("+ ");
        }
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    Node* a = NULL;
    Node* b = NULL;
    Node* result = NULL;
    int n, co, ex;

    printf("\nPolynomial A");
    printf("\nEnter the number of terms:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter coefficient and exponent:");
        scanf("%d%d", &co, &ex);
        a = insertTerm(a, co, ex);
    }
    printf("\nPolynomial B");
    printf("\nEnter the number of terms:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        printf("\nEnter coefficient and exponent:");
        scanf("%d%d", &co, &ex);
        b = insertTerm(b, co, ex); // Corrected this line
    }
    printf("Polynomial A: ");
    displayPolynomial(a);
    printf("Polynomial B: ");
    displayPolynomial(b);

    result = addPolynomials(a, b);
    printf("Sum of Polynomials A and B: ");
    displayPolynomial(result);

    return 0;
}
