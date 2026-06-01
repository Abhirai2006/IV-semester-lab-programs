/*
 * Program  : Binary Search
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Searching
 * Complexity: O(log n)
 *
 * Aim: Implement Binary Search to efficiently locate an element in a sorted array.
 */

#include <stdio.h>

/* Returns index of key in sorted arr[0..n-1], or -1 if not found */
int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;  /* avoids integer overflow */
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] <  key)
            low  = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(void)
{
    int n, key, arr[100];

    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter search key: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);
    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found.\n", key);

    return 0;
}
