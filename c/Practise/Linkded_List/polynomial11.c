#include <stdio.h>
#include <stdlib.h>

// Define the structure of a polynomial node
typedef struct PolyNode {
    int coef;
    int expon;
    struct PolyNode* link;
} Node;

// Function to create a new polynomial node
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
void insertTerm(Node** poly, int coef, int expon) {
    Node* temp = *poly;
    Node* newnode = createPolyNode(coef, expon);

    if (*poly == NULL) {
        *poly = newnode;
        return;
    }

    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newnode;
}

// Function to add two polynomials
Node* addPolynomials(Node* a, Node* b) {
    Node* result = NULL;
    Node* tempa = a;
    Node* tempb = b;

    while (tempa != NULL && tempb != NULL) {
        if (tempa->expon == tempb->expon) {
            int sum = tempa->coef + tempb->coef;
            if (sum != 0) {
                insertTerm(&result, sum, tempa->expon);
            }
            tempa = tempa->link;
            tempb = tempb->link;
        } else if (tempa->expon > tempb->expon) {
            insertTerm(&result, tempa->coef, tempa->expon);
            tempa = tempa->link;
        } else {
            insertTerm(&result, tempb->coef, tempb->expon);
            tempb = tempb->link;
        }
    }

    while (tempa != NULL) {
        insertTerm(&result, tempa->coef, tempa->expon);
        tempa = tempa->link;
    }

    while (tempb != NULL) {
        insertTerm(&result, tempb->coef, tempb->expon);
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
    int n, coef, expon;

    // Insert terms into polynomial A
    printf("Enter the number of terms for polynomial A: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for polynomial A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &coef, &expon);
        insertTerm(&a, coef, expon);
    }

    // Insert terms into polynomial B
    printf("\nEnter the number of terms for polynomial B: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for polynomial B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &coef, &expon);
        insertTerm(&b, coef, expon);
    }

    // Display polynomials A and B
    printf("\nPolynomial A: ");
    displayPolynomial(a);
    printf("\nPolynomial B: ");
    displayPolynomial(b);

    // Add polynomials A and B
    Node* sum = addPolynomials(a, b);
    printf("\nSum of Polynomials A and B: ");
    displayPolynomial(sum);

    // Free memory
    Node* temp;
    while (a != NULL) {
        temp = a;
        a = a->link;
        free(temp);
    }
    while (b != NULL) {
        temp = b;
        b = b->link;
        free(temp);
    }
    while (sum != NULL) {
        temp = sum;
        sum = sum->link;
        free(temp);
    }

    return 0;
}
