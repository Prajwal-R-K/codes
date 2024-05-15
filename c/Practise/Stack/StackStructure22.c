#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define the Stack structure
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

Stack stack;  // Declare a global stack

// Function to initialize the stack
void initialize() {
    stack.top = -1;
}

// Function to check if the stack is empty
int isEmpty() {
    return (stack.top == -1);
}

// Function to check if the stack is full
int isFull() {
    return (stack.top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack overflow, cannot push %d\n", value);
        return;
    }
    stack.arr[++stack.top] = value;
    printf("%d pushed to the stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return a special value to indicate underflow
    }
    return stack.arr[stack.top--];
}

// Function to get the top element of the stack without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1; // Return a special value to indicate empty stack
    }
    return stack.arr[stack.top];
}

// Function to display the elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.arr[i]);
    }
    printf("\n");
}

int main() {
    // Example usage
    initialize();

    push(10);
    push(20);
    push(30);

    display();

    printf("Top element: %d\n", peek());

    printf("Popped element: %d\n", pop());

    display();

    return 0;
}
