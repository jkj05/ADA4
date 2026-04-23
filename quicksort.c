#include <stdio.h>
#include <stdlib.h> // Required for rand() and malloc
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    srand(time(NULL)); // Seed the randomizer once

    // 1. Generate a random n (e.g., between 50,000 and 100,000)
    int n = (rand() % 50000) + 50000;
    printf("Randomly selected n: %d\n", n);

    // 2. Dynamically allocate memory (safer for large n)
    int *arr = (int *)malloc(n * sizeof(int));

    // 3. Fill array with random elements (0 to 99,999)
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    clock_t start, end;

    printf("Sorting...\n");
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    // 4. Removed the "print sorted array" loop to save console space
    // and focus purely on the execution time.

    double time_taken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Time Taken: %f milli-seconds\n", time_taken);

    // Clean up memory
    free(arr);

    return 0;
}
