/*
 * Interactive Sorting Algorithm Demonstration
 * 
 * Features requested by professor:
 * 1. Randomly fills an array (not ordered)
 * 2. Menu displays which sorting algorithm to use
 * 3. You choose one, it sorts the array and shows execution time
 */

#include "../include/sorting.h"

// Display menu
void displayMenu() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║         SORTING ALGORITHMS - INTERACTIVE MENU            ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("  Choose a sorting algorithm:\n\n");
    printf("  1. Bubble Sort\n");
    printf("  2. Bubble Sort (Optimized)\n");
    printf("  3. Gnome Sort\n");
    printf("  4. Radix Sort\n");
    printf("  5. Quick Sort\n");
    printf("  6. Heap Sort\n");
    printf("  7. Bucket Sort\n");
    printf("  8. Run ALL algorithms (compare)\n");
    printf("  0. Exit\n");
    printf("\n");
    printf("  Enter your choice: ");
}

// Time measurement helper
double executeAndMeasure(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

double executeQuick(int arr[], int n) {
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

double executeRadix(int arr[], int n) {
    clock_t start = clock();
    radixSort(arr, n, 5);  // Assume 5 digits max
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

double executeBucket(int arr[], int n, int maxVal) {
    clock_t start = clock();
    bucketSortInt(arr, n, maxVal);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

void runSingleAlgorithm(int choice, int *original, int n, int maxVal) {
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    copyArray(original, arr, n);
    double time_ms = 0;
    const char *algName = "";
    
    printf("\n");
    printf("┌────────────────────────────────────────────────────────┐\n");
    
    switch(choice) {
        case 1:
            algName = "Bubble Sort";
            time_ms = executeAndMeasure(bubbleSort, arr, n);
            break;
        case 2:
            algName = "Bubble Sort (Optimized)";
            time_ms = executeAndMeasure(bubbleSortOpt, arr, n);
            break;
        case 3:
            algName = "Gnome Sort";
            time_ms = executeAndMeasure(gnomeSort, arr, n);
            break;
        case 4:
            algName = "Radix Sort";
            time_ms = executeRadix(arr, n);
            break;
        case 5:
            algName = "Quick Sort";
            time_ms = executeQuick(arr, n);
            break;
        case 6:
            algName = "Heap Sort";
            time_ms = executeAndMeasure(heapSort, arr, n);
            break;
        case 7:
            algName = "Bucket Sort";
            time_ms = executeBucket(arr, n, maxVal);
            break;
        default:
            printf("│ Invalid choice!                                        │\n");
            printf("└────────────────────────────────────────────────────────┘\n");
            free(arr);
            return;
    }
    
    printf("│ Algorithm: %-43s │\n", algName);
    printf("│ Array size: %-42d │\n", n);
    printf("│ Status: %-46s │\n", isSorted(arr, n) ? "✓ SORTED SUCCESSFULLY" : "✗ FAILED");
    printf("│                                                        │\n");
    printf("│ ⏱  Execution Time: %.3f ms %*s │\n", time_ms, (int)(29 - (time_ms >= 1000 ? 4 : time_ms >= 100 ? 3 : time_ms >= 10 ? 2 : 1)), "");
    printf("└────────────────────────────────────────────────────────┘\n");
    
    // Show sample of sorted array
    printf("\nSorted array (first 15 elements): ");
    printArray(arr, n < 15 ? n : 15);
    
    free(arr);
}

void runAllAlgorithms(int *original, int n, int maxVal) {
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║         COMPARING ALL SORTING ALGORITHMS                ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("  %-25s %15s %10s\n", "Algorithm", "Time (ms)", "Status");
    printf("  ───────────────────────────────────────────────────────\n");
    
    // Bubble Sort
    copyArray(original, arr, n);
    double t = executeAndMeasure(bubbleSort, arr, n);
    printf("  %-25s %15.3f %10s\n", "Bubble Sort", t, isSorted(arr, n) ? "✓" : "✗");
    
    // Bubble Sort Optimized
    copyArray(original, arr, n);
    t = executeAndMeasure(bubbleSortOpt, arr, n);
    printf("  %-25s %15.3f %10s\n", "Bubble Sort (Optimized)", t, isSorted(arr, n) ? "✓" : "✗");
    
    // Gnome Sort
    copyArray(original, arr, n);
    t = executeAndMeasure(gnomeSort, arr, n);
    printf("  %-25s %15.3f %10s\n", "Gnome Sort", t, isSorted(arr, n) ? "✓" : "✗");
    
    // Radix Sort
    copyArray(original, arr, n);
    t = executeRadix(arr, n);
    printf("  %-25s %15.3f %10s\n", "Radix Sort", t, isSorted(arr, n) ? "✓" : "✗");
    
    // Quick Sort
    copyArray(original, arr, n);
    t = executeQuick(arr, n);
    printf("  %-25s %15.3f %10s\n", "Quick Sort", t, isSorted(arr, n) ? "✓" : "✗");
    
    // Heap Sort
    copyArray(original, arr, n);
    t = executeAndMeasure(heapSort, arr, n);
    printf("  %-25s %15.3f %10s\n", "Heap Sort", t, isSorted(arr, n) ? "✓" : "✗");
    
    // Bucket Sort
    copyArray(original, arr, n);
    t = executeBucket(arr, n, maxVal);
    printf("  %-25s %15.3f %10s\n", "Bucket Sort", t, isSorted(arr, n) ? "✓" : "✗");
    
    printf("  ───────────────────────────────────────────────────────\n");
    free(arr);
}

int main(void) {
    srand(time(NULL));
    
    // Get array size from user
    int n;
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║    WELCOME TO SORTING ALGORITHMS DEMONSTRATION          ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Enter the size of the array to sort: ");
    fflush(stdout);
    if (scanf("%d", &n) != 1) {
        printf("Invalid input!\n");
        return 1;
    }
    // Clear input buffer safely
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    if (n <= 0 || n > 1000000) {
        printf("Invalid array size! Please enter between 1 and 1,000,000\n");
        return 1;
    }
    
    // Generate random array
    int maxVal = 100000;
    int *original = (int *)malloc(n * sizeof(int));
    if (!original) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    generateRandomArray(original, n, maxVal);
    
    printf("\n✓ Random array generated with %d elements\n", n);
    printf("  Value range: 0 to %d\n", maxVal);
    printf("\n  Array preview (first 15 elements): ");
    printArray(original, n < 15 ? n : 15);
    
    // Interactive menu loop
    int choice;
    do {
        displayMenu();
        fflush(stdout);
        
        if (scanf("%d", &choice) != 1) {
            // Invalid input, clear buffer and continue
            while ((c = getchar()) != '\n' && c != EOF);
            printf("\n⚠  Invalid input! Please enter a number.\n");
            continue;
        }
        // Clear input buffer safely
        while ((c = getchar()) != '\n' && c != EOF);
        
        if (choice == 0) {
            printf("\nThank you for using the Sorting Algorithms Demo!\n");
            break;
        } else if (choice == 8) {
            runAllAlgorithms(original, n, maxVal);
        } else if (choice >= 1 && choice <= 7) {
            runSingleAlgorithm(choice, original, n, maxVal);
        } else {
            printf("\n⚠  Invalid choice! Please select 0-8.\n");
        }
        
    } while (choice != 0);
    
    free(original);
    return 0;
}
