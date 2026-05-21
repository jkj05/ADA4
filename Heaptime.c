#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int a[], int n, int i) {

    int big = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[big])
        big = l;

    if (r < n && a[r] > a[big])
        big = r;

    if (big != i) {
        swap(&a[i], &a[big]);
        heapify(a, n, big);
    }
}

void heapSort(int a[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void printArr(int a[], int n) {

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main() {

        int n;

        printf("Enter number of elements: ");
        scanf("%d", &n);

        int a[n];


        for (int i = 0; i < n; i++) {
//            a[i] = rand() % 1000;
        }

       // printf("\nGenerated array:\n");
        //printArr(a, n);

        clock_t st, en;

        st = clock();

        heapSort(a, n);

        en = clock();

       // printf("\nSorted array:\n");
       // printArr(a, n);

        double t = (double)(en - st) / CLOCKS_PER_SEC;

        printf("\nTime taken = %lf seconds\n", t);
    return 0;
}
