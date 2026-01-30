/*
 * Gnome Sort Implementation
 * 
 * Principle: Start at the beginning of the array, compare two consecutive
 * elements (i, i+1). If they are in order, move one step towards the end.
 * Otherwise, swap them and move one step towards the start. If at the start,
 * move one step towards the end.
 * 
 * Complexity:
 *   Best Case: O(n) - when array is already sorted
 *   Worst Case: O(n²) - when array is reverse sorted
 *   Space: O(1)
 */

#include "../include/sorting.h"

void gnomeSort(int arr[], int n) {
    int index = 0;
    
    while (index < n) {
        if (index == 0) {
            index++;
        }
        
        if (arr[index] >= arr[index - 1]) {
            // Elements are in order, move forward
            index++;
        } else {
            // Elements are out of order, swap and move backward
            swap(&arr[index], &arr[index - 1]);
            index--;
        }
    }
}

/*
 * Gnome Sort with counters for analysis
 */
void gnomeSortCounted(int arr[], int n) {
    int index = 0;
    
    while (index < n) {
        if (index == 0) {
            index++;
        }
        
        comparison_count++;
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            swap_counted(&arr[index], &arr[index - 1]);
            index--;
        }
    }
}
