#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global counters for algorithm analysis
extern long long comparison_count;
extern long long swap_count;
extern size_t memory_used;

// Reset counters
void reset_counters(void);

// Utility functions
void swap(int *a, int *b);
void swap_counted(int *a, int *b);  // Counts swaps
int compare_counted(int a, int b);   // Counts comparisons, returns a > b
void printArray(int arr[], int n);
void copyArray(int src[], int dest[], int n);
int isSorted(int arr[], int n);

// Test case generators
void generateRandomArray(int arr[], int n, int maxVal);
void generateSortedArray(int arr[], int n);
void generateReverseSortedArray(int arr[], int n);
void generateNearlySortedArray(int arr[], int n, int swaps);
void generateDuplicatesArray(int arr[], int n, int uniqueValues);

// Bubble Sort
void bubbleSort(int arr[], int n);
void bubbleSortOpt(int arr[], int n);
void bubbleSortCounted(int arr[], int n);  // With counters

// Gnome Sort
void gnomeSort(int arr[], int n);
void gnomeSortCounted(int arr[], int n);  // With counters

// Radix Sort
int key(int x, int i);
void sortAux(int arr[], int n, int digit);
void radixSort(int arr[], int n, int k);

// Quick Sort
int partition(int arr[], int p, int r);
void quickSort(int arr[], int p, int r);
void quickSortCounted(int arr[], int p, int r);  // With counters

// Heap Sort
void heapify(int arr[], int n, int i);
void buildMaxHeap(int arr[], int n);
void heapSort(int arr[], int n);
void heapSortCounted(int arr[], int n);  // With counters

// Bucket Sort (for floating point [0,1))
void bucketSort(float arr[], int n);
// Bucket Sort for integers
void bucketSortInt(int arr[], int n, int maxVal);

// Stability demonstration
typedef struct {
    int value;
    int original_index;
} StableElement;

void demonstrateStability(void);

#endif // SORTING_H
