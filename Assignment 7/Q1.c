#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Initialize the top of the stack as NULL (empty stack)
struct Node* top = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = createNode(value);
    if (top == NULL) {
        top = newNode;  // If the stack is empty, the new node becomes the top
    } else {
        newNode->next = top;  // Link the new node to the current top
        top = newNode;        // Set the new node as the top of the stack
    }
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow: Stack is empty\n");
        return -1;
    }
    struct Node* temp = top;  // Store the current top node
    int poppedValue = top->data;  // Get the data of the top node
    top = top->next;  // Move the top to the next node
    free(temp);  // Free the memory of the old top node
    return poppedValue;
}

// Function to peek at the top element without popping it
int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;  // Return the data of the top node
}

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to display the elements of the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack
int main() {
    int choice, value;

    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

