#include<stdio.h>
#include<stdlib.h>
#define M 5
int a[M];
void linearprobing(int key,int index)
{
    int i;
    if(a[index]==-1)
    {
        a[index]=key;
        return;
    }
    printf("collosion\n");
    i=index;
    do{
        i=(i+1)%M;
        if(a[i]==-1)
        {
            printf("collision is resolved by linear probing");
            a[i]=key;
            return;
        }
    }while(i!=index);
    printf("hash table is full");
    exit(0);
}
void display()
{int i;
    printf("index \t key\n");
    for(i=0;i<M;i++)
    printf("%d\t%d\n",i,a[i]);
}
int main()
{
    int key,index,i,input;
    for(i=0;i<M;i++)
    a[i]=-1;
    do{
        printf("enter the key");
        scanf("%4d",&key);
        index=key%M;
        linearprobing(key,index);
        display();
        printf("enter 1 to continue else 0");
        scanf("%d",&input);
    }while(input==1);
}