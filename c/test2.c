#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   returnSize=(int*)malloc(2*sizeof(int));
    for(int i=0;i<numsSize;i++)
    {
            if((nums[i]+nums[i+1])==target)
            {
                returnSize[0]=i;
                returnSize[1]=i+1;

                return returnSize;
            }
        
        
    }
    return returnSize;
}
void main()
{
    int a[]={1,8,1};
    int *b;
    b=twoSum(a,3,9,b);
     for (int i = 0; i < 2; i++) {
        printf("%d ", b[i]);
     }
     prin
}