#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct NODE {
    int data;
    struct NODE* next;
} NODE;

void swap_linked_list(NODE* a, NODE* b) {
    const int temp = a->data;
    a->data = b->data;
    b->data = temp;
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

void selectionSort_list(NODE* head) {
    NODE* current = head;
    while (current->next != NULL) {
        NODE* min = current;
        NODE* r = current->next;
        while (r != NULL) {
            if (min->data > r->data)
                min = r;
            r = r->next;
        }
        swap_linked_list(min, current);
        current = current->next;
    }
}

struct timespec diff_timespec(struct timespec start, struct timespec end) {
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


void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int size, int exp) {
    const int RADIX = 10; // The number of possible digits (0-9)
    int output[size];
    int count[RADIX] = {};
    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % RADIX]++;
    for (int i = 1; i < RADIX; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
        count[(arr[i] / exp) % RADIX]--;
    }
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

// Radix Sort
void radixSort(int arr[], int size) {
    int max = getMax(arr, size);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, size, exp);
}

# define MAX_BiG_SORT 100000-1


int main() {
    int arrBub[] = {64, 25, 12, 22, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 99};
    int arrIns[] = {64, 25, 12, 22, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 99};
    int arrSel[] = {64, 25, 12, 22, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 99};
    int arrMerge[] = {64, 25, 12, 22, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 99};
    int arrQuick[] = {64, 25, 12, 22, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 99};


    int arrQuick100k[MAX_BiG_SORT];
    int arrMerge100k[MAX_BiG_SORT];
    int arrRadix100k[MAX_BiG_SORT];
    const NODE* head = &(NODE){0, NULL};
    NODE* temp = (NODE*)head;

    for (int i = 0; i < MAX_BiG_SORT; ++i) {
        const int value = rand() * rand() % 100000;
        arrQuick100k[i] = value;
        arrMerge100k[i] = value;
        arrRadix100k[i] = value;

        temp->next = malloc(sizeof(NODE));
        temp->next->data = value;
        temp->next->next = NULL;
        temp = temp->next;

        //printf("%i", arrQuick100k[i]);
    }

    temp = (NODE*)head;
    long long count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    printf("Depths of list: %lli \n", count);

    struct timespec start, end;
    int size = sizeof(arrBub) / sizeof(arrBub[0]);

    printf("Original array:        ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrBub[i]);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    bubbleSort(arrBub, size);
    clock_gettime(CLOCK_REALTIME, &end);


    printf("\nSorted bubble (%llins)   array:", (diff_timespec(start, end).tv_nsec));
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrBub[i]);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    insertionSort(arrIns, size);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\nSorted insertion array: (%llins)", (diff_timespec(start, end).tv_nsec));
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrIns[i]);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    selectionSort_list(head);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\nSorted selection array:(%llins)", (diff_timespec(start, end).tv_nsec));
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrSel[i]);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    mergeSort(arrMerge, 0, size - 1);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\nSorted merge array:(%llins)", (diff_timespec(start, end).tv_nsec));
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrMerge[i]);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    quickSort(arrQuick, 0, size - 1);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\nSorted quick array:(%llins)", (diff_timespec(start, end).tv_nsec));
    for (int i = 0; i < size; ++i) {
        printf("%d ", arrMerge[i]);
    }

    // 100k

    clock_gettime(CLOCK_REALTIME, &start);
    mergeSort(arrMerge100k, 0, MAX_BiG_SORT - 1);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\nSorted 100k merge array in (%lius)", (diff_timespec(start, end).tv_nsec / 1000));
    for (int i = 0; i < MAX_BiG_SORT; ++i) {
        //printf("%d ", arrMerge100k[i]);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    quickSort(arrQuick100k, 0, MAX_BiG_SORT - 1);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\nSorted 100k quick array in (%llius)", (diff_timespec(start, end).tv_nsec / 1000));

    clock_gettime(CLOCK_REALTIME, &start);
    quickSort(arrRadix100k, 0, MAX_BiG_SORT - 1);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\nSorted 100k radix array in (%llius)", (diff_timespec(start, end).tv_nsec / 1000));

    NODE* current = head;
    while (current != NULL) {
        NODE* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
