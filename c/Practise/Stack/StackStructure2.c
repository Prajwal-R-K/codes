#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
//This structure uses a single array int arr[MAX_SIZE] to store the elements of the stack.
//More effecient
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

//struct Stack stack;  // Declared as global

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}


 /*
 If we  declared stack as global(as show in comment.) then no need above code follow the below code.
int isEmpty() {
    return (stack.top == -1);
}
*/

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("%d pushed to the stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return a special value to indicate underflow
    }
    return stack->arr[stack->top--];
}

// Function to get the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return a special value to indicate empty stack
    }
    return stack->arr[stack->top];
}

// Function to display the elements of the stack
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));

    display(&stack);

    return 0;
}
