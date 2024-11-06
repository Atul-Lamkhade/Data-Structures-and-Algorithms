/*Implement binary search */

#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid; // Return the index where the key is found
        }

        // If the key is greater, ignore the left half
        if (arr[mid] < key) {
            low = mid + 1;
        }
        // If the key is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    return -1; // Return -1 if the key is not found
}

int main() {
    int n, key, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Call the binarySearch function
    result = binarySearch(arr, n, key);

    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
