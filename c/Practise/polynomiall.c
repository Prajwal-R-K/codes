#include <stdio.h>

#define MAX 100

typedef struct {
    float degree;
    int coeff[MAX];
} polynomial;

void printPolynomial(polynomial poly) {
    printf("%dx^%d ", poly.coeff[0], poly.degree);
    for (int i = 1; i <= poly.degree; i++) {
        if (poly.coeff[i] != 0)
            printf("+ %dx^%d ", poly.coeff[i], poly.degree - i);
    }
    printf("\n");
}

int main() {
    polynomial poly1;
    poly1.degree = 3.0;
    poly1.coeff[0] = 2;
    poly1.coeff[1] = -1;
    poly1.coeff[2] = 3;
    poly1.coeff[3] = 0;

    polynomial poly2;
    poly2.degree = 2.0;
    poly2.coeff[0] = 1;
    poly2.coeff[1] = 0;
    poly2.coeff[2] = -2;

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    return 0;
}
