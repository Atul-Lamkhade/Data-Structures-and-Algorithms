/*Implement doubly linked list operations */

#include<stdio.h>
#include<stdlib.h>

// Define a node for the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL; // Initially, the list is empty

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(int value) 
{
    struct Node* newNode = createNode(value);
    if (head == NULL)
     {
        head = newNode;
    } 
    else 
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted at the beginning: %d\n", value);
}

// Insert at the end
void insertAtEnd(int value) 
{
    struct Node* newNode = createNode(value);
    if (head == NULL) 
    {
        head = newNode;
    } 
    else 
    {
        struct Node* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node inserted at the end: %d\n", value);
}

// Delete from the beginning
void deleteFromBeginning() 
{
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == NULL)  // Only one node in the list
    {
        head = NULL;
    } 
    else 
    {
        head = head->next;
        head->prev = NULL;
    }
    printf("Node deleted from the beginning: %d\n", temp->data);
    free(temp);
}

// Delete from the end
void deleteFromEnd() 
{
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == NULL)  // Only one node in the list
    {
        head = NULL;
    } 
    else 
    {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    printf("Node deleted from the end: %d\n", temp->data);
    free(temp);
}

// Display the doubly linked list
void displayList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main()
{
    int choice, value;
    while (1) 
    {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                displayList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
