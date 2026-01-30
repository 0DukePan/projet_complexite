/*
 * Advanced Test Driver for Sorting Algorithms
 * 
 * Features:
 * - Multiple test cases (random, sorted, reverse, nearly sorted, duplicates)
 * - Comparison and swap counting
 * - Memory usage tracking
 * - Stability demonstration
 * - Comprehensive output
 */

#include "../include/sorting.h"

// Time measurement
double measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

double measureTimeQuick(int arr[], int n) {
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

double measureTimeRadix(int arr[], int n, int k) {
    clock_t start = clock();
    radixSort(arr, n, k);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

double measureTimeBucket(int arr[], int n, int maxVal) {
    clock_t start = clock();
    bucketSortInt(arr, n, maxVal);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

// Run algorithm with counters
typedef struct {
    double time_ms;
    long long comparisons;
    long long swaps;
} AlgorithmStats;

AlgorithmStats runBubbleCounted(int arr[], int n) {
    AlgorithmStats stats;
    reset_counters();
    clock_t start = clock();
    bubbleSortCounted(arr, n);
    clock_t end = clock();
    stats.time_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    stats.comparisons = comparison_count;
    stats.swaps = swap_count;
    return stats;
}

AlgorithmStats runGnomeCounted(int arr[], int n) {
    AlgorithmStats stats;
    reset_counters();
    clock_t start = clock();
    gnomeSortCounted(arr, n);
    clock_t end = clock();
    stats.time_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    stats.comparisons = comparison_count;
    stats.swaps = swap_count;
    return stats;
}

AlgorithmStats runQuickCounted(int arr[], int n) {
    AlgorithmStats stats;
    reset_counters();
    clock_t start = clock();
    quickSortCounted(arr, 0, n - 1);
    clock_t end = clock();
    stats.time_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    stats.comparisons = comparison_count;
    stats.swaps = swap_count;
    return stats;
}

AlgorithmStats runHeapCounted(int arr[], int n) {
    AlgorithmStats stats;
    reset_counters();
    clock_t start = clock();
    heapSortCounted(arr, n);
    clock_t end = clock();
    stats.time_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    stats.comparisons = comparison_count;
    stats.swaps = swap_count;
    return stats;
}

void printStats(const char* name, AlgorithmStats stats, int passed) {
    printf("  %-20s %s  Time: %8.3f ms  Comparisons: %10lld  Swaps: %10lld\n",
           name, passed ? "PASS" : "FAIL", stats.time_ms, stats.comparisons, stats.swaps);
}

void runTestCase(const char* testName, int original[], int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    AlgorithmStats stats;
    
    printf("\n%s (n=%d)\n", testName, n);
    printf("  %-20s %-4s  %-18s  %-22s  %-15s\n", "Algorithm", "Test", "Time", "Comparisons", "Swaps");
    printf("  %s\n", "--------------------------------------------------------------------------------");
    
    // Bubble Sort
    copyArray(original, arr, n);
    stats = runBubbleCounted(arr, n);
    printStats("Bubble Sort", stats, isSorted(arr, n));
    
    // Gnome Sort
    copyArray(original, arr, n);
    stats = runGnomeCounted(arr, n);
    printStats("Gnome Sort", stats, isSorted(arr, n));
    
    // Quick Sort
    copyArray(original, arr, n);
    stats = runQuickCounted(arr, n);
    printStats("Quick Sort", stats, isSorted(arr, n));
    
    // Heap Sort
    copyArray(original, arr, n);
    stats = runHeapCounted(arr, n);
    printStats("Heap Sort", stats, isSorted(arr, n));
    
    free(arr);
}

void runAllTestCases(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║              SORTING ALGORITHMS - COMPREHENSIVE ANALYSIS                     ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════╝\n");
    
    // Test Case 1: Random array
    generateRandomArray(arr, n, 10000);
    runTestCase("TEST CASE 1: Random Array", arr, n);
    
    // Test Case 2: Already sorted
    generateSortedArray(arr, n);
    runTestCase("TEST CASE 2: Already Sorted (Best Case for some)", arr, n);
    
    // Test Case 3: Reverse sorted
    generateReverseSortedArray(arr, n);
    runTestCase("TEST CASE 3: Reverse Sorted (Worst Case for some)", arr, n);
    
    // Test Case 4: Nearly sorted
    generateNearlySortedArray(arr, n, n / 20);  // 5% elements swapped
    runTestCase("TEST CASE 4: Nearly Sorted (5% swapped)", arr, n);
    
    // Test Case 5: Many duplicates
    generateDuplicatesArray(arr, n, 10);  // Only 10 unique values
    runTestCase("TEST CASE 5: Many Duplicates (10 unique values)", arr, n);
    
    free(arr);
}

void printUsageGuide(void) {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║              ALGORITHM SELECTION GUIDE - WHEN TO USE EACH                    ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("┌─────────────────┬──────────────────────────────────────────────────────────┐\n");
    printf("│ Algorithm       │ Best Use Case                                            │\n");
    printf("├─────────────────┼──────────────────────────────────────────────────────────┤\n");
    printf("│ Bubble Sort     │ Educational purposes, very small arrays (n < 20)        │\n");
    printf("│ Gnome Sort      │ Simple implementation needed, nearly sorted data        │\n");
    printf("│ Quick Sort      │ General purpose, large random arrays                    │\n");
    printf("│ Heap Sort       │ Guaranteed O(n log n), memory-constrained environments  │\n");
    printf("│ Radix Sort      │ Integers with fixed digit count, large datasets         │\n");
    printf("│ Bucket Sort     │ Uniformly distributed data in known range               │\n");
    printf("└─────────────────┴──────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("Stability Matters? Use: Bubble Sort, Gnome Sort, Radix Sort, or Bucket Sort\n");
    printf("Memory Limited?    Use: Heap Sort (O(1) extra space)\n");
    printf("Unknown Data?      Use: Quick Sort or Heap Sort\n");
}

int main(int argc, char *argv[]) {
    int n = 1000;
    int benchmark_mode = 0;
    int analysis_mode = 0;
    int maxVal = 10000;
    int k = 5;
    
    if (argc > 1) {
        if (strcmp(argv[1], "stability") == 0) {
            demonstrateStability();
            return 0;
        } else if (strcmp(argv[1], "analysis") == 0) {
            analysis_mode = 1;
            n = (argc > 2) ? atoi(argv[2]) : 1000;
        } else if (strcmp(argv[1], "guide") == 0) {
            printUsageGuide();
            return 0;
        } else {
            n = atoi(argv[1]);
        }
    }
    if (argc > 2 && strcmp(argv[2], "benchmark") == 0) {
        benchmark_mode = 1;
    }
    
    srand(time(NULL));
    
    if (analysis_mode) {
        runAllTestCases(n);
        demonstrateStability();
        printUsageGuide();
        return 0;
    }
    
    // Original benchmark mode
    int *original = (int *)malloc(n * sizeof(int));
    int *arr = (int *)malloc(n * sizeof(int));
    
    generateRandomArray(original, n, maxVal);
    
    if (!benchmark_mode) {
        printf("=== Sorting Algorithms Test ===\n\n");
        printf("Original array (first 20 elements): ");
        printArray(original, n < 20 ? n : 20);
        printf("\n");
    }
    
    // Test all algorithms
    copyArray(original, arr, n);
    double time_bubble = measureTime(bubbleSort, arr, n);
    if (!benchmark_mode) printf("Bubble Sort: %s (%.3f ms)\n", isSorted(arr, n) ? "PASS" : "FAIL", time_bubble);
    
    copyArray(original, arr, n);
    double time_bubble_opt = measureTime(bubbleSortOpt, arr, n);
    if (!benchmark_mode) printf("Bubble Sort Opt: %s (%.3f ms)\n", isSorted(arr, n) ? "PASS" : "FAIL", time_bubble_opt);
    
    copyArray(original, arr, n);
    double time_gnome = measureTime(gnomeSort, arr, n);
    if (!benchmark_mode) printf("Gnome Sort: %s (%.3f ms)\n", isSorted(arr, n) ? "PASS" : "FAIL", time_gnome);
    
    copyArray(original, arr, n);
    double time_radix = measureTimeRadix(arr, n, k);
    if (!benchmark_mode) printf("Radix Sort: %s (%.3f ms)\n", isSorted(arr, n) ? "PASS" : "FAIL", time_radix);
    
    copyArray(original, arr, n);
    double time_quick = measureTimeQuick(arr, n);
    if (!benchmark_mode) printf("Quick Sort: %s (%.3f ms)\n", isSorted(arr, n) ? "PASS" : "FAIL", time_quick);
    
    copyArray(original, arr, n);
    double time_heap = measureTime(heapSort, arr, n);
    if (!benchmark_mode) printf("Heap Sort: %s (%.3f ms)\n", isSorted(arr, n) ? "PASS" : "FAIL", time_heap);
    
    copyArray(original, arr, n);
    double time_bucket = measureTimeBucket(arr, n, maxVal);
    if (!benchmark_mode) printf("Bucket Sort: %s (%.3f ms)\n", isSorted(arr, n) ? "PASS" : "FAIL", time_bucket);
    
    if (benchmark_mode) {
        printf("%d,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f\n",
               n, time_bubble, time_bubble_opt, time_gnome, time_radix,
               time_quick, time_heap, time_bucket);
    } else {
        printf("\n=== All tests completed ===\n");
        printf("\nRun './sort_test analysis' for comprehensive analysis\n");
        printf("Run './sort_test stability' for stability demonstration\n");
        printf("Run './sort_test guide' for algorithm selection guide\n");
    }
    
    free(original);
    free(arr);
    
    return 0;
}
