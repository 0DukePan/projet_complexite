/*
 * Radix Sort Implementation (LSD - Least Significant Digit)
 * 
 * Sorts integers by processing individual digits.
 * Uses counting sort as a subroutine (sortAux).
 * 
 * key(x, i): Returns the i-th digit (0 = units, 1 = tens, 2 = hundreds, etc.)
 * sortAux(T, n, i): Stable sort by the i-th digit using counting sort
 * radixSort(T, n, k): Sort by distribution using k digits
 * 
 * Complexity:
 *   Best Case: O(k × n) where k = number of digits
 *   Worst Case: O(k × n)
 *   Space: O(n + 10) = O(n)
 */

#include "../include/sorting.h"

/*
 * Extract the i-th digit from x
 * i = 0 -> units digit
 * i = 1 -> tens digit
 * i = 2 -> hundreds digit
 * etc.
 */
int key(int x, int i) {
    int divisor = 1;
    for (int j = 0; j < i; j++) {
        divisor *= 10;
    }
    return (x / divisor) % 10;
}

/*
 * Counting sort by the digit at position 'digit'
 * This is a stable sort which is essential for radix sort to work correctly
 */
void sortAux(int arr[], int n, int digit) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};
    
    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[key(arr[i], digit)]++;
    }
    
    // Convert counts to positions
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array (traverse from right to left to maintain stability)
    for (int i = n - 1; i >= 0; i--) {
        int d = key(arr[i], digit);
        output[count[d] - 1] = arr[i];
        count[d]--;
    }
    
    // Copy output back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }j
    
    free(output);
}

/*
 * Radix Sort
 * k = number of digits to process
 * Sorts integers between 0 and 10^k - 1
 */
void radixSort(int arr[], int n, int k) {
    for (int i = 0; i < k; i++) {
        sortAux(arr, n, i);
    }
}
