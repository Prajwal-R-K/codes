#include<stdio.h>
#define size 10
int top = -1;
struct Tree
{
int data;
struct Tree *lptr, *rptr;
};
typedef struct Tree node;
node *root,*stack[size];

void push(node *temp) //function to push
{
if(top == size-1)
{
Printf("stack full");
return;
}
stack[++top] = temp;
}

node *pop() //function to pop
{
if(top == – 1)
{
printf("stack empty");
return;
}
return(stack[top--]);
}

void iterative_inorder(node *root)
{
node *cur = root;
while(1)
{
while(cur!=NULL)
{
push(cur);
cur=cur->lptr;
}
if(top == -1) break;
cur = pop();
printf("%d ", cur->data);
cur=cur->rptr;
}
}