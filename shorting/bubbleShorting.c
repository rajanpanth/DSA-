#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        //swapped = 0; // Optimization: check if any swapping happenedA
        
        for (j = 0; j < n - i - 1; j++) {
            // if (arr[j] > arr[j + 1]) {  ->ACENDING
                if (arr[j] < arr[j + 1]) { 
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
               // swapped = 1;
            }
        }
        
        // If no two elements were swapped by inner loop, then break
        if (swapped == 0)
            break;
    }
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data) / sizeof(data[0]);
    
    bubbleSort(data, n);
    
    printf("Sorted Array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}