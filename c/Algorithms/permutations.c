#include<stdio.h>
void swap(char a[],int i,int j)
{
    char temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void permut(char a[],int l,int u)
{
    if(l==u)
        printf("\n%s",a);
    for(int i=l;i<=u;i++)
    {
        swap(a,l,i);
        permut(a,l+1,u);
        swap(a,l,i);
    }
}

void main()
{
    char s[]="ABC";
    permut(s,0,2);
}