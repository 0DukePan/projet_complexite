/*
 * Heap Sort Implementation
 * 
 * Uses a binary heap data structure represented as an array.
 * For a node at index i:
 *   - Parent: (i-1)/2
 *   - Left child: 2*i + 1
 *   - Right child: 2*i + 2
 * 
 * Process:
 * 1. Build a max-heap from the input array
 * 2. Repeatedly extract the maximum (root) and place at the end
 * 3. Reduce heap size and heapify the root
 * 
 * Complexity:
 *   Best Case: O(n log n)
 *   Worst Case: O(n log n)
 *   Average Case: O(n log n)
 *   Space: O(1) - in-place sorting
 */

#include "../include/sorting.h"

/*
 * Heapify subtree rooted at index i
 * n is the size of the heap
 * Maintains the max-heap property
 */
void heapify(int arr[], int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child
    
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    // If right child is larger than current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

/*
 * Build a max-heap from an unsorted array
 * Start from the last non-leaf node and heapify all nodes
 */
void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

/*
 * Heap Sort
 * 1. Build max-heap
 * 2. Extract max (swap with last), reduce heap size, heapify root
 */
void heapSort(int arr[], int n) {
    // Build max-heap
    buildMaxHeap(arr, n);
    
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (maximum) to end
        swap(&arr[0], &arr[i]);
        
        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

/*
 * Heapify with counters
 */
static void heapifyCounted(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n) {
        comparison_count++;
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }
    
    if (right < n) {
        comparison_count++;
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }
    
    if (largest != i) {
        swap_counted(&arr[i], &arr[largest]);
        heapifyCounted(arr, n, largest);
    }
}

/*
 * Heap Sort with counters for analysis
 */
void heapSortCounted(int arr[], int n) {
    // Build max-heap with counting
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyCounted(arr, n, i);
    }
    
    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap_counted(&arr[0], &arr[i]);
        heapifyCounted(arr, i, 0);
    }
}
