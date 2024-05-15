#include<stdio.h>
int count=0;
void TowerOf(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("\nMove from %c to %c",a,c);
        count++;
    }
    else
    {
        TowerOf(n-1,a,c,b);
        printf("\nMove from %c to %c",a,c);
        count++;
        TowerOf(n-1,b,a,c);
    }
}
void main()
{
    int n;
    printf("\nEnter the no. of disk:");scanf("%d",&n);
    TowerOf(n,'A','B','C');
    printf("\n%d",count);
}