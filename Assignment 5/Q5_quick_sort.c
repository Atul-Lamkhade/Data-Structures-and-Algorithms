/*Implement quick sort */

#include <stdio.h>
int n,left,right,temp;
void quickSort(int A[] , int left , int right)
{
  if(left<right)
  {
    int pivot =A[right];
    int i=left-1;
for (int j = left; j <= right - 1; j++) {
    if (A[j] < pivot) {  // If the current element is smaller than the pivot
        ++i;             // Increment the index of the smaller element
        temp = A[i];     // Swap A[i] with A[j] to place the smaller element before the pivot
        A[i] = A[j];
        A[j] = temp;
    }
}

temp = A[i + 1];       // Swap the pivot element with the element at A[i+1]
A[i + 1] = A[right];   // This places the pivot in its correct sorted position
A[right] = temp; 

// Recursively apply the quick sort to the left and right subarrays
quickSort(A, left, i);     // Sort elements on the left of the pivot
quickSort(A, i + 2, right); // Sort elements on the right of the pivot

  }
}
int main()
{

printf("Enter the number of elements : ");
scanf("%d",&n);

int A[n];

printf("Enter the elements : ");
for(int i=0;i<n;i++)
{
    scanf("%d",&A[i]);
}

int left=0;
int right=n-1;

quickSort(A,0,n-1);  //calling the quicksort function

printf("Array after sorting : ");
for(int i=0;i<n;i++)
{
    printf("%d ",A[i]);
}

return 0;
}











// void swap(int arr[], int a, int b) {
//     int temp = arr[a];
//     arr[a] = arr[b];
//     arr[b] = temp;
// }

// int partition(int arr[], int low, int high) {
//    int pivot = arr[high]; // Choosing the last element as pivot
//     int i = low - 1; // Index of smaller element

//     for (int j = low; j < high; j++) {
//         // If current element is smaller than or equal to pivot
//         if (arr[j] <= pivot) {
//             i++; // increment index of smaller element
//             swap(arr, i, j);
//         }
//     }
//     swap(arr, i + 1, high); // Place the pivot in the correct position
//     return (i + 1);
// }

// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         // pi is partitioning index, arr[pi] is now at the right place
//         int pi = partition(arr, low, high);

//         // Recursively sort elements before and after partition
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// int main() {
   
//     int n;

//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     int arr[n];
//     printf("Enter %d elements:\n", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     quickSort(arr, 0, n- 1);

//     printf("\nSorted array is:\n");
//     printArray(arr, n);

//     return 0;
// }
