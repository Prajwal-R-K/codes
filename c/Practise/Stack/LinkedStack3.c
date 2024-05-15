#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node *stack=NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(int data) {
    Node* newNode = createNode(data);
    if(stack==NULL)
    {
        stack=newNode;
        return;
    }
    newNode->next=stack;
    stack=newNode;
}

// Function to pop an element from the stack
int pop() {
    if (stack == NULL) {
        printf("\nStack is empty");
        return -1;
    }
    Node* temp =stack;
    int data=stack->data;
    stack=stack->next;
    free(temp);
    return data;
}


// Function to display the stack
void display() {
    if (stack==NULL)
    {
        printf("\nStack is empty");
        return;
    }
    printf("Stack: ");
    Node *temp=stack;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp =temp->next;
    }
}

int main() {
   int n,ele;
    printf("\n1-Push\t2-pop\t3-Display\t4-exit:");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&n);   
        switch(n)
        {
            case 1: printf("\nEnter the element:");scanf("%d",&ele);
                    push(ele);break;
            case 2: ele=pop();
                    if(ele!=-1)
                        printf("\nDeleted element is %d",ele);        
                    break;
            case 3:display();break;
            case 4:exit(0);
            default:printf("\n WRONG CHOICE");
        }     
    }
}