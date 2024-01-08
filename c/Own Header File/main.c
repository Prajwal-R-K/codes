#include<stdio.h>
#include "math.h"
void main()
{
    int a=add(2,3);
    int b=sub(5,2);
    printf("\nadd=%d",a);
    printf("\nsub=%d",b);
    printf("\nMul=%d",mul(5,9));
}
//compile both msin.c and source.c at a time---i.e {gcc main.c source.c}  (or) {gcc main.c source.c -omain} (or) {gcc main.c source.c -oHeader}
//Now run---i.e {.\main}
//cd "c:\Users\Administrator\Desktop\codes\c\Own Header File\" ; if ($?) { gcc main.c source.c -o main } ; if ($?) { .\main }