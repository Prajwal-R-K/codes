#include <stdio.h>

#define MAX_SIZE 10

//This structure uses an array of structures struct Stack stack[MAX_SIZE],
// where each structure has an int member (int key) to store the actual data.
// Less effecient
struct Stack {
    int key;
};

struct Stack stack[MAX_SIZE];
int top = -1; // Initialize top index to -1

// Function to check if the stack is empty
int isEmpty() {
    return (top == -1);
}

// Function to check if the stack is full
int isFull() {
    return (top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack overflow, cannot push %d\n", value);
        return;
    }
    stack[++top].key = value;
    printf("%d pushed to the stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return a special value to indicate underflow
    }
    return stack[top--].key;
}

// Function to get the top element of the stack without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1; // Return a special value to indicate empty stack
    }
    return stack[top].key;
}

// Function to display the elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i].key);
    }
    printf("\n");
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