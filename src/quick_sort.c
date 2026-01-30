/*
 * Quick Sort Implementation
 * 
 * Divide and Conquer approach:
 * 1. Divide: Partition the array around a pivot so that elements <= pivot
 *    are on the left and elements > pivot are on the right.
 * 2. Conquer: Recursively sort the two subarrays.
 * 3. Combine: No work needed as sorting is done in-place.
 * 
 * Complexity:
 *   Best Case: O(n log n) - balanced partitions
 *   Worst Case: O(n²) - already sorted (poor pivot choice)
 *   Average Case: O(n log n)
 *   Space: O(log n) - recursion stack
 * 
 * Recurrence relation:
 *   Best: T(n) = 2T(n/2) + O(n) => O(n log n)
 *   Worst: T(n) = T(n-1) + O(n) => O(n²)
 */

#include "../include/sorting.h"

/*
 * Partition function (Lomuto scheme)
 * Uses the last element as pivot
 * Returns the final position of the pivot
 */
int partition(int arr[], int p, int r) {
    int pivot = arr[r];  // Use last element as pivot
    int i = p - 1;       // Index of smaller element
    
    for (int j = p; j < r; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Place pivot in correct position
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

/*
 * Quick Sort recursive function
 * Sorts arr[p..r] in place
 */
void quickSort(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);  // Sort left subarray
        quickSort(arr, q + 1, r);  // Sort right subarray
    }
}

/*
 * Partition with counters
 */
static int partitionCounted(int arr[], int p, int r) {
    int pivot = arr[r];
    int i = p - 1;
    
    for (int j = p; j < r; j++) {
        comparison_count++;
        if (arr[j] <= pivot) {
            i++;
            swap_counted(&arr[i], &arr[j]);
        }
    }
    
    swap_counted(&arr[i + 1], &arr[r]);
    return i + 1;
}

/*
 * Quick Sort with counters for analysis
 */
void quickSortCounted(int arr[], int p, int r) {
    if (p < r) {
        int q = partitionCounted(arr, p, r);
        quickSortCounted(arr, p, q - 1);
        quickSortCounted(arr, q + 1, r);
    }
}
