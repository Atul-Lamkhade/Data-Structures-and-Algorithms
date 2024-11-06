/*Implement sequential search */

#include<stdio.h>

int sequentialSearch(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++) 
    {
        if(arr[i] == key) 
        {
            return i; // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main()
 {
    int n, key, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: \n", n);
    for(int i = 0; i < n; i++)
     {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Call the sequentialSearch function
    result = sequentialSearch(arr, n, key);

    if(result != -1) 
    {
        printf("Element %d found at index %d.\n", key, result);
    } else
     {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
