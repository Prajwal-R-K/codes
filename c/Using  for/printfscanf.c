#include <stdio.h>

int main() {
    int limit,i=0,d;
    

    // Prompt the user to enter a limit
    printf("Enter the limit: ");
    scanf("%d", &limit);
    int a[limit];

    // Using scanf() within the for loop
    for (printf("Enter the element"),scanf("%d",&a[i])   ;  i <limit-1   ;   i++,printf("Enter the element"),scanf("%d",&a[i])) //Give {} intead of giving statements as given below line
  d++;//No use -- to avoid bugs or we not used {} curly braces hence the  exceution(control)will  execute only next line and continue the for loop
    i=0;
    for (printf("Elements are"); i < limit;printf("\n%d",a[i]),i++){}
  

    return 0;
}
