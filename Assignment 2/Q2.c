/*Implement queues using Arrays*/


#include <stdio.h>
#define SIZE 10             //defining max size to 10

int queue[SIZE];
int front = -1;           //initializing front=-1
int rear = -1;              //initializing rear=-1
int x;

int IsEmpty() 
{
    return (front == -1 && rear == -1);
}

int IsFull()
 { 
    return (rear == SIZE - 1);
    
}

void enqueue(int x)         //function for inserting in queue
{
    if (IsFull())
     {
        printf("Queue is full. Can't insert element.\n");
        return;
    } 
    else if (IsEmpty()) 
    {
        front = rear = 0;
    }
     else 
    {
        rear++;
    }
    queue[rear] = x;
}

int dequeue()             //function for deleting element from queue
 {
    if (IsEmpty()) 
    {
        printf("Queue is empty. Nothing to delete.\n");
        return -1;
    } 
    else if (front == rear) 
    {
        int temp = queue[front];
        front = rear = -1; // Reset queue
        return temp;
    } 
    else
     {
        int temp = queue[front];
        front++;
        return temp;
    }
}

void print() //functon for printing 
{
    if (IsEmpty())    //first it will check ie it empty or not
    {
        printf("Queue is empty.\n");
    } 
    else 
    {
        printf("Elements of the Queue: ");
        for (int i = front; i <= rear; i++) 
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int choice;
    do {
        printf("-------Menu------\n");             //menu driven choices
        printf("1: Insert element in queue\n");
        printf("2: Delete element from queue\n");
        printf("3: Check queue is empty or not\n");
        printf("4: Print elements of queue\n");
        printf("5: Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert in queue: ");
                scanf("%d", &x);
                enqueue(x);        //function for inserting in a queue
                break;
            case 2:
                x = dequeue();     //function for deleting from queue
                if (x != -1) 
                {
                    printf("Dequeued element: %d\n", x);
                }
                break;
            case 3:
                if (IsEmpty())      //function for checking queue is empty or not
              
                {
                    printf("Queue is empty.\n");
                }
                else 
                 {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                print();            //function for printing the queue
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);//function will stop executing again and again after user gives 5
                             //comes out of the function

    return 0;
}
