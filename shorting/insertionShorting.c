#include <stdio.h>

void insertionSort(int array[], int size) {
    int step, key, j;

    for (step = 1; step < size; step++) {
        key = array[step];
        j = step - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    int array[] = {23, 78, 45, 8, 32, 56};
    int size = sizeof(array) / sizeof(array[0]);

    insertionSort(array, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
