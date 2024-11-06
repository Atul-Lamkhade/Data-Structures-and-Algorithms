//Implement selection sort 

#include<stdio.h>
#include<stdlib.h>


int main()
{
    
    int n,i,j,min,index,temp;
    printf("Enter the range :\n");

    int A[n];
    scanf("%d",&n);
    printf("Enter %d numbers :\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
for (i = 0; i < n - 1; i++) {
    min = A[i];        // Assume the first unsorted element is the minimum
    index = i;         // Store the index of the assumed minimum element

    // Find the minimum element in the remaining unsorted array
    for (j = i + 1; j < n; j++) {
        if (min > A[j]) {  // Check if the current element is smaller than the assumed minimum
            min = A[j];    // Update the minimum value
            index = j;     // Update the index of the new minimum element
        }
    }

    // Swap the found minimum element with the first element of the unsorted part
    temp = A[i];
    A[i] = A[index];
    A[index] = temp;
}

    printf("Array after sorting :");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }

    return 0;
}



//Time complexity O(n^2)
