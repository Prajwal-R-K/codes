#include<stdio.h>
#include<stdbool.h>
void main()
{
    int a=printf("Hello");//Value of a will be no. of characters in string
    printf("\n %d",a);
    
    int (*p)[5];//Creates an array p of pointers.
    *p[0]=1;
    printf("\n%d\n",*p[0]);

    printf(5+"Test_Quiz");//print  the string after 5 characters of given String.

    char b[20]="gyug";
    printf("\n%d",sizeof(b));
    
int i=1;
for( ; ; )
{
    printf("\n%d ",i++);
    if(i>10);
    break;
}
bool aa=true;
printf("\n%d",aa);

}