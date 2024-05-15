#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* array; // Memory allocated at runtime
    int top;
    int capacity;  // Total size of stack taken from user
};

// Function to initialize a dynamic stack
void initialize(struct Stack* stack, int capacity) {
    stack->array = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
}

// Function to check if the dynamic stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the dynamic stack is full
int isFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

// Function to double the capacity of the dynamic stack
void resize(struct Stack* stack) {
    stack->capacity *= 2;
    stack->array = (int*)realloc(stack->array, stack->capacity * sizeof(int));
}

// Function to push an element onto the dynamic stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        resize(stack);
    }
    stack->array[++stack->top] = value;
    printf("%d pushed to the stack\n", value);
}

// Function to pop an element from the dynamic stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return a special value to indicate underflow
    }
    return stack->array[stack->top--];
}

// Function to get the top element of the dynamic stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return a special value to indicate empty stack
    }
    return stack->array[stack->top];
}

// Function to display the elements of the dynamic stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to deallocate memory for the dynamic stack
void destroy(struct Stack* stack) {
    free(stack->array);
    stack->top = -1;
    stack->capacity = 0;
}

int main() {
    struct Stack stack;
    int initialCapacity = 5; // Adjust the initial capacity as needed

    initialize(&stack, initialCapacity);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));

    display(&stack);

    // Deallocate memory for the dynamic stack
    destroy(&stack);

    return 0;
}
