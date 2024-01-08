//"GCD" and "HCF" both refer to the same mathematical concept: the "Greatest Common Divisor" or "Highest Common Factor."
// The GCD of two or more integers is the largest positive integer that divides each of the integers without leaving a remainder.
//Both GCD and LCM are same
#include <stdio.h>
int main()
{
    int n1, n2, i, gcd;

    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);

    for(i=1; i <= n1 && i <= n2; ++i)
    {
        // Checks if i is factor of both integers
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }

    printf("G.C.D of %d and %d is %d", n1, n2, gcd);

    return 0;
}