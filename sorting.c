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

struct timespec diff_timespec(struct timespec start, struct timespec end)
{
    struct timespec temp;
    if ((end.tv_nsec - start.tv_nsec) < 0) {
        temp.tv_sec = end.tv_sec - start.tv_sec - 1;
        temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec - start.tv_sec;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    return temp;
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
    struct timespec start,end;
    clock_gettime(CLOCK_REALTIME, &start);
    bubbleSort(arrBub, size);
    clock_gettime(CLOCK_REALTIME, &end);


    printf("\nSorted bubble (%llins)   array:", (diff_timespec(start,end).tv_nsec));
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrBub[i]);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    insertionSort(arrIns, size);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\nSorted insertion array: (%llins)",(diff_timespec(start,end).tv_nsec));
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrIns[i]);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    selectionSort(arrSel, size);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\nSorted selection array:(%llins)",(diff_timespec(start,end).tv_nsec));
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrSel[i]);
    }

    return 0;
}