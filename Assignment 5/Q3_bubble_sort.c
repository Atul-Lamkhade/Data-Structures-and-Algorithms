//Implement bubble sort 

#include<stdio.h>
#include<stdlib.h>


int main()
{
    
    int i,j,temp,n;
    printf("Enter the range :\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter %d numbers :\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    
for (i = 0; i < n; i++) {
    // Loop through the array and push the largest element in the unsorted part to the end
    for (j = 0; j < n - 1; j++) {
        if (A[j] > A[j + 1]) {  // Check if the current element is greater than the next element
            temp = A[j + 1];    // Store the next element in a temporary variable
            A[j + 1] = A[j];    // Move the current element to the next position
            A[j] = temp;        // Replace the current position with the next element
        }
    }
}


    printf("Array after sorting :");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }


    return 0;
}



//Time complexity O(n^2)