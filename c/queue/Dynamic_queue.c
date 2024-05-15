#include<stdio.h>
#include<stdlib.h>
int size=1;
int *q;
int f=0;
int r=-1;
int count=0;
void enqueue()
{
    int item ;
    if(count==size)
    {
        printf("queue full : update size");
        size++;
        q=(int*)realloc(q,size*sizeof(int));
    }
    printf("enter the item");
    scanf("%d",&item);
    r=r+1;
    q[r]=item;
    count++;
}
void dequeue()
{
    if(f>r)
    {
        printf("queue is empty"); 
        return;
    }
    printf("deleted item is %d",q[f]);
    f=f+1;
    size--;
    q=(int*)realloc(q,size*sizeof(int));
    count++;
}
int main()
{
    q=(int*)malloc(sizeof(int));
    enqueue();
 
    enqueue();
    enqueue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}