/*
 * Bubble Sort Implementation
 * 
 * Standard Bubble Sort:
 *   Best Case: O(n²)
 *   Worst Case: O(n²)
 *   Space: O(1)
 * 
 * Optimized Bubble Sort (with early termination):
 *   Best Case: O(n) - when array is already sorted
 *   Worst Case: O(n²)
 *   Space: O(1)
 */

#include "../include/sorting.h"

// Utility swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Standard Bubble Sort
 * Repeatedly steps through the list, compares adjacent elements
 * and swaps them if they are in the wrong order.
 */
void bubbleSort(int arr[], int n) {
    int change = 1;
    
    while (change) {
        change = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                change = 1;
            }
        }
    }
}

/*
 * Optimized Bubble Sort
 * After the i-th traversal, the last i elements are in their final places.
 * The traversal can stop one index before the previous one.
 */
void bubbleSortOpt(int arr[], int n) {
    int m = n - 1;
    int change = 1;
    
    while (change) {
        change = 0;
        for (int i = 0; i < m; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                change = 1;
            }
        }
        m--;
    }
}

/*
 * Bubble Sort with counters for analysis
 */
void bubbleSortCounted(int arr[], int n) {
    int change = 1;
    
    while (change) {
        change = 0;
        for (int i = 0; i < n - 1; i++) {
            if (compare_counted(arr[i], arr[i + 1])) {
                swap_counted(&arr[i], &arr[i + 1]);
                change = 1;
            }
        }
    }
}
