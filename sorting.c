#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(int arr[], int size) {
    bool swapped = false;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break; // early termination
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

int main() {

    int  arrBub[] = {64, 25, 12, 22, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 99};
    int  arrIns[] = {64, 25, 12, 22, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 99};
    int  arrSel[] = {64, 25, 12, 22, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 99};
    int size = sizeof(arrBub) / sizeof(arrBub[0]);

    printf("Original array:        ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrBub[i]);
    }

    bubbleSort(arrBub, size);

    printf("\nSorted bubble    array:");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrBub[i]);
    }

    insertionSort(arrIns, size);

    printf("\nSorted insertion array:");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrIns[i]);
    }

    selectionSort(arrSel, size);

    printf("\nSorted selection array:");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrSel[i]);
    }

    return 0;
}