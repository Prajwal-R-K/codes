#include <stdio.h>
#include<stdlib.h>

#define MAX_STACKS 10

/*
struct Stack
{
    int *memory;
    int top[MAX_STACKS];
    int boundary[MAX_STACKS];
};
typedef struct Stack stack;
void intialize()
{
    stack.memory=(int*)malloc(MEMORY_SIZE*sizeof(int));
    stack.top[0] = stack.boundary[0] = -1;
    for (int j = 1; j < n; j++) 
    {
        stack.top[j] = stack.boundary[j] = (MEMORY_SIZE / n) * j;
    }
    stack.boundary[n] = MEMORY_SIZE - 1;
}
*/

int *memory; // Array
int top[MAX_STACKS];
int boundary[MAX_STACKS];
int  MEMORY_SIZE, n;

// Function to initialize the multiple stacks
void initialize() 
{
    memory=(int*)malloc(MEMORY_SIZE*sizeof(int));
    top[0] = boundary[0] = -1;
    for (int j = 1; j < n; j++) 
    {
        top[j] = boundary[j] = (MEMORY_SIZE / n) * j;
    }
    boundary[n] = MEMORY_SIZE - 1;
}

// Function to check if a specific stack is full
int isFull(int stackIndex) 
{
    return (top[stackIndex] == boundary[stackIndex+1]);
}

// Function to check if a specific stack is empty
int isEmpty(int stackIndex) {
    return (top[stackIndex] == boundary[stackIndex]);
}

// Function to push an element onto a specific stack
void push(int stackIndex, int value) 
{
    if (isFull(stackIndex)) 
    {
        printf("Stack %d overflow, cannot push %d\n", stackIndex, value);
        return;
    }
    memory[++top[stackIndex]] = value;
    printf("%d pushed to Stack %d\n", value, stackIndex);
}

// Function to pop an element from a specific stack
int pop(int stackIndex) 
{
    if (isEmpty(stackIndex)) 
    {
        printf("Stack %d underflow, cannot pop\n", stackIndex);
        return -1; // Return a special value to indicate underflow
    }
    return memory[top[stackIndex]--];
}

// Function to display the elements of a specific stack
void display(int stackIndex) 
{
    if (isEmpty(stackIndex)) 
    {
        printf("Stack %d is empty\n", stackIndex);
        return;
    }

    printf("Stack %d elements: ", stackIndex);
    for (int i = top[stackIndex]; i > boundary[stackIndex]; i--)
    {
        printf("%d ", memory[i]);
    }
    printf("\n");
}

int main() {
int choice,StackIndex,value;
printf("\nEnter the Maximum size:");scanf("%d",&MEMORY_SIZE);
printf("Enter the number of Stacks:");scanf("%d",&n);   //Set the number of stacks
initialize();
while(1)
{
    printf("\n1-Push\t2-pop\t3-display\t4-Exit");
    printf("\nEnter your choice:");scanf("%d",&choice);
    if(choice>=1&&choice<=3)
    {
        printf("Enter the stack number:");scanf("%d",&StackIndex);
        if(StackIndex>=n || StackIndex<0)
        {
            printf("\nThere is no stack ");
            continue;
        }
    }
    switch(choice)
    {
        case 1:printf("Enter the Value to insert:");scanf("%d",&value);
               push(StackIndex,value);
               break;
        case 2:value=pop(StackIndex);
               if(value!=-1)
                    printf("Poped element is %d\n",value);
               break;
        case 3:display(StackIndex);
               break;
        case 4:exit(0);
        default:printf("\nWrong Entry");
                break;
    }
}
return 0;
}
