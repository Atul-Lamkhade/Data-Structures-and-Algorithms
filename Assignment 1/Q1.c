/*Write a menu driven program to perform operations in an array. 
*****MENU******
1. Insert 
2. Delete 
3. Search 
4. Display 
5. Exit*/
#include <stdio.h>
#define MAX 10    //set max size to 10


void insertElement(int arr[], int size)     //function for insert element
{
    if (size >= MAX)      //conditon when size is greater than max size
    {                                    
        printf("Array is full.\n");
    } 
    else 
    {
        int value;
        printf("Enter element to add: ");
        scanf("%d", &value);
        arr[size] = value;

        printf("Element added successfully.\n");
    }
}

void deleteElement(int arr[], int size)     //function for delete element
{
    if (size == 0)   //when size is equal to 0
    {
        printf("Array is empty, nothing to delete.\n");
    } 
    else
    {
        int position;
        printf("Enter the position (0 to %d) to delete: ", size - 1);
        scanf("%d", &position);
        if (position < 0 || position >= size) 
        {
            printf("Invalid position.\n");
        } 
        else 
        {
            for (int i = position; i < size - 1; i++) 
            {
                arr[i] = arr[i + 1];
            }
            printf("Element deleted successfully.\n");
        }
    }
}

void searchElement(int arr[], int size)  //function for search element
{
    if (size == 0) 
    {
        printf("Array is empty.\n");
    }
     else
    {
        int value;
        printf("Enter element to search: ");
        scanf("%d", &value);
        for (int i = 0; i < size; i++)     //loop for searching
        {
            if (arr[i] == value) 
            {
                printf("Element %d found at position %d.\n", value, i);
                break;
            }
        }
    }
}

void displayElement(int arr[], int size)       //function for display element
{
    if (size == 0)
     {
        printf("Array is empty.\n");
    } else
     {
        printf("Array elements: ");
        for (int i = 0; i < size; i++)
         {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}


int main()           //main function
{
    int arr[MAX];       //array of max size
    int size = 0; // Initialize size to 0
    int choice;

    do {
        printf("-------Menu------\n");
        printf("1 : Insert element in array\n");
        printf("2 : Delete element from array\n");
        printf("3 : Search element in array\n");
        printf("4 : Display elements of array\n");
        printf("5 : Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertElement(arr, size);     //function for insertion
                size++; // Update size after insertion
                break;

            case 2:
                deleteElement(arr, size);   //function for deletion
                size--; // Update size after deletion
                break;

            case 3:
                searchElement(arr, size);     //function for searching
                break;

            case 4:
                displayElement(arr, size);     //function for display
                break;

            case 5:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);       //condition for user presses 5 program will exit.

    return 0;
}
