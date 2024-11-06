//Implement circular linked list operations 

#include<stdio.h>
#include<stdlib.h>

// Define a node for the circular linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Initially, the list is empty

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
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
        newNode->next = head;  // Circular reference
    } 
    else 
    {
        struct Node* temp = head;
        while (temp->next != head) 
        { 
            temp = temp->next;
        }
        newNode->next = head; // Point new node to head
        temp->next = newNode; // Last node now points to new node
        head = newNode;       // New node becomes the head
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
        newNode->next = head;  // Circular reference
    } 
    else 
    {
        struct Node* temp = head;
        while (temp->next != head) { // Find the last node
            temp = temp->next;
        }
        temp->next = newNode;   // Last node points to new node
        newNode->next = head;   // New node points back to head
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
    if (head->next == head) // Only one node in the list
    { 
        head = NULL;
        free(temp);
    } 
    else 
    {
        struct Node* last = head;
        while (last->next != head) // Find the last node 
        { 
            last = last->next;
        }
        head = head->next;  // Move head to the next node
        last->next = head;  // Update last node to point to new head
        free(temp);         // Free the old head
    }
    printf("Node deleted from the beginning\n");
}

// Delete from the end
void deleteFromEnd() 
{
    if (head == NULL) 
    {
        printf("The list is empty.There is no element to delete.\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head)   // Only one node in the list
    { 
        head = NULL;
        free(temp);
    } 
    else 
    {
        struct Node* prev = NULL;
        while (temp->next != head) // Find the last node
        { 
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;  // Second last node points to head
        free(temp);         // Free the last node
    }
    printf("Node deleted from the end\n");
}

// Display the circular linked list
void displayList() 
{
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop when we loop back to the head
    printf("\n");
}

// Main function
int main() 
{
    int choice, value;
    while (1) 
    {
        printf("\n--- Circular Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
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
