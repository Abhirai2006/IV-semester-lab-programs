/*
 * Program  : Merge Sort
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Divide & Conquer
 * Complexity: O(n log n)
 *
 * Aim: Sort an array using the Merge Sort algorithm.
 */

#include <stdio.h>

/*
 * merge: merges two sorted halves of arr[] back into one sorted segment.
 *   left_start  : starting index of the left half
 *   mid         : ending index of the left half
 *   right_end   : ending index of the right half
 */
void merge(int arr[], int left_start, int mid, int right_end) {
    int left_len  = mid - left_start + 1;
    int right_len = right_end - mid;

    int left_arr[left_len];
    int right_arr[right_len];

    /* Copy data into temporary arrays */
    for (int i = 0; i < left_len;  i++)
        left_arr[i]  = arr[left_start + i];
    for (int j = 0; j < right_len; j++)
        right_arr[j] = arr[mid + 1 + j];

    int left_idx  = 0;        /* index for left_arr  */
    int right_idx = 0;        /* index for right_arr */
    int merged_idx = left_start;  /* index for merged arr */

    /* Merge the two halves in sorted order */
    while (left_idx < left_len && right_idx < right_len) {
        if (left_arr[left_idx] <= right_arr[right_idx])
            arr[merged_idx++] = left_arr[left_idx++];
        else
            arr[merged_idx++] = right_arr[right_idx++];
    }

    /* Copy remaining elements */
    while (left_idx  < left_len)
        arr[merged_idx++] = left_arr[left_idx++];
    while (right_idx < right_len)
        arr[merged_idx++] = right_arr[right_idx++];
}

/*
 * mergeSort: recursively divides arr[left_start..right_end] and sorts it.
 */
void mergeSort(int arr[], int left_start, int right_end) {
    if (left_start < right_end) {
        int mid = left_start + (right_end - left_start) / 2;

        mergeSort(arr, left_start, mid);          /* sort left half  */
        mergeSort(arr, mid + 1,    right_end);    /* sort right half */
        merge(arr, left_start, mid, right_end);   /* merge both      */
    }
}

int main(void) {
    int size, arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
