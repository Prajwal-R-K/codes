#include <stdio.h>

int main() {
    printf("Before jump\n");
int a,sum=0;
jump_here:
    printf("Enter +ve no:");
    scanf("%d",&a);
    sum=sum+a;
    if(a>0)
    goto jump_here;
    

    printf("After jump\n"); 
    return 0;
}
