#include<stdio.h>
struct poly{
    int coeff,exp;
}p1[20],p2[20],p3[30];

void read(poly a)
{   int n;
    printf("\nEnter the number of terms");
    scanf("%d",&n);
    printf("\nEnter the coeff and exponent");
    for(i=0;i<n;i++)
    {   printf("\nTerm -%d",i+1)
        scanf("%d%d",a[i].coeff,a[i].exp)
    }
}
void clculate()
{
    int sum=0;

}

