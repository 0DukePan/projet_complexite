/*
 * Utility Functions and Counters
 * Provides common functionality for all sorting algorithms
 */

#include "../include/sorting.h"

// Global counters
long long comparison_count = 0;
long long swap_count = 0;
size_t memory_used = 0;

void reset_counters(void) {
    comparison_count = 0;
    swap_count = 0;
    memory_used = 0;
}

// Swap with counting
void swap_counted(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swap_count++;
}

// Compare with counting (returns 1 if a > b)
int compare_counted(int a, int b) {
    comparison_count++;
    return a > b;
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return 0;
    }
    return 1;
}

// ============================================================
// TEST CASE GENERATORS
// ============================================================

void generateRandomArray(int arr[], int n, int maxVal) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % maxVal;
    }
}

void generateSortedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void generateReverseSortedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void generateNearlySortedArray(int arr[], int n, int numSwaps) {
    // Start with sorted array
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    // Perform a few random swaps
    for (int i = 0; i < numSwaps && n > 1; i++) {
        int idx1 = rand() % n;
        int idx2 = rand() % n;
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
}

void generateDuplicatesArray(int arr[], int n, int uniqueValues) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % uniqueValues;
    }
}

// ============================================================
// STABILITY DEMONSTRATION
// ============================================================

// Bubble sort for StableElement (stable)
void stableBubbleSort(StableElement arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                StableElement temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection sort for StableElement (unstable)
void unstableSelectionSort(StableElement arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].value < arr[min_idx].value) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            StableElement temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void demonstrateStability(void) {
    printf("\n=== STABILITY DEMONSTRATION ===\n");
    printf("Sorting pairs (value, original_index) with duplicate values.\n");
    printf("A STABLE sort preserves the original order of equal elements.\n\n");
    
    // Test array with duplicates
    StableElement stable_arr[] = {
        {3, 0}, {1, 1}, {2, 2}, {1, 3}, {3, 4}, {2, 5}
    };
    StableElement unstable_arr[6];
    int n = 6;
    
    // Copy for unstable sort
    for (int i = 0; i < n; i++) {
        unstable_arr[i] = stable_arr[i];
    }
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("(%d,idx%d) ", stable_arr[i].value, stable_arr[i].original_index);
    }
    printf("\n\n");
    
    // Stable sort (Bubble Sort)
    stableBubbleSort(stable_arr, n);
    printf("After STABLE sort (Bubble Sort):\n  ");
    for (int i = 0; i < n; i++) {
        printf("(%d,idx%d) ", stable_arr[i].value, stable_arr[i].original_index);
    }
    printf("\n  Notice: Elements with value 1 maintain order: idx1 before idx3\n");
    printf("          Elements with value 2 maintain order: idx2 before idx5\n");
    printf("          Elements with value 3 maintain order: idx0 before idx4\n\n");
    
    // Unstable sort (Selection Sort)
    unstableSelectionSort(unstable_arr, n);
    printf("After UNSTABLE sort (Selection Sort):\n  ");
    for (int i = 0; i < n; i++) {
        printf("(%d,idx%d) ", unstable_arr[i].value, unstable_arr[i].original_index);
    }
    printf("\n  Order of equal elements may be changed!\n\n");
    
    printf("STABLE algorithms: Bubble Sort, Gnome Sort, Radix Sort, Bucket Sort\n");
    printf("UNSTABLE algorithms: Quick Sort, Heap Sort\n");
}
