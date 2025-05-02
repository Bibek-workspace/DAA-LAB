#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;

    // Traverse the array from the second element to the last
    for (i = 1; i < n; i++) {
        key = arr[i];  // The element to be inserted into sorted part
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Insert the key at the correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};  // Sample array
    int n = sizeof(arr) / sizeof(arr[0]);  // Size of the array

    printf("Original array:\n");
    printArray(arr, n);

    // Call Insertion Sort
    insertionSort(arr, n);

    printf("Sorted array using Insertion Sort:\n");
    printArray(arr, n);

    return 0;
}
