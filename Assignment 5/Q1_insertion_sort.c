//Implement insertion sort 

#include<stdio.h>
#include<stdlib.h>


int main()
{
    
    int i,j,pivot,n;
    printf("Enter the range :\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter %d numbers :\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    
    for (i = 1; i < n; i++) {
    pivot = A[i]; // Set the current element as the pivot for insertion

    // Shift elements in the sorted portion to the right until finding the right position for the pivot
    for (j = i; A[j - 1] > pivot && j > 0; j--) {
        A[j] = A[j - 1]; // Move the larger element one position to the right
    }

    A[j] = pivot; // Place the pivot in its correct sorted position
       
    }

    printf("Array after sorting :");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }


    return 0;
}



//Time complexity O(n^2)