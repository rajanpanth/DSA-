#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to sort array (bubble sort)
void sortArray(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Binary search function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;  // Element not found
}

int main() {
    int n, key, i;
    
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Seed random number generator
    srand(time(NULL));
    
    // Fill array with random numbers
    printf("Generated array: ");
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Random numbers between 0-99
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // Sort the array for binary search
    sortArray(arr, n);
    
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    printf("Enter number to search: ");
    scanf("%d", &key);

    clock_t start = clock();   // start time

    int index = binarySearch(arr, n, key);
    
    clock_t end = clock();     // end time
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if(index != -1)
        printf("Element %d found at index %d\n", key, index);
    else
        printf("Element %d not found\n", key);

    printf("Time taken to search: %f seconds\n", time_taken);

    return 0;
}
