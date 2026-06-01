/*
 * Program  : Merge Sort
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Divide & Conquer
 * Complexity: O(n log n)
 *
 * Aim: Sort an array using the Merge Sort algorithm.
 */

#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int left_len  = m - l + 1;
    int right_len = r - m;

    int L[left_len], R[right_len];

    for (int i = 0; i < left_len;  i++)
        L[i] = arr[l + i];
    for (int j = 0; j < right_len; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < left_len && j < right_len)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < left_len)
        arr[k++] = L[i++];
    while (j < right_len)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    int n, arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
