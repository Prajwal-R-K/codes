#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
void peek()
{
    printf("\n%d",stack[top]);
}

int isfull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(top==-1)
        return 1;
    else   
        return 0;
}

void push(int ele)
{
    if(isfull())
        printf("\n STACK OVERFLOW");
    else 
        stack[++top]=ele;    
}

int pop()
{
    if(isempty())
    {   printf("\nSTACK UNDERFLOW");
        return -1;
    }
    else        
        return stack[top--];
}

void display()
{
    if(isempty())
       {    printf("\nSTACK IS EMPTY");
            return;
       }
    int i;
    printf("\n");
    for(i=top;i>=0;i--)
        printf("%d\t",i);
}
int main()
{
    int n,ele;
    printf("\n1-Push\t2-pop\t3-peek\t4-Display\t5-exit:");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&n);   
        switch(n)
        {
            case 1: printf("\nEnter the element:");scanf("%d",&ele);
                    push(ele);break;
            case 2: ele=pop();
                    printf("\nDeleted element is %d",ele);        
                    break;
            case 3:peek();break;
            case 4:display();break;
            case 5:exit(0);
            default:printf("\n WRONG CHOICE");
        }     
    }
}