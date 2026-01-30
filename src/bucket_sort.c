/*
 * Bucket Sort Implementation
 * 
 * Algorithm (for floating point numbers in [0, 1)):
 * 1. Create n empty buckets (linked lists)
 * 2. Insert each element A[i] into bucket B[floor(n * A[i])]
 * 3. Sort each bucket using insertion sort
 * 4. Concatenate all buckets in order
 * 
 * Complexity:
 *   Best Case: O(n) - when elements are uniformly distributed
 *   Average Case: O(n) - with uniform distribution assumption
 *   Worst Case: O(n²) - when all elements fall into one bucket
 *   Space: O(n)
 */

#include "../include/sorting.h"

// Node structure for linked list bucket
typedef struct Node {
    float value;
    struct Node *next;
} Node;

/*
 * Create a new node
 */
Node* createNode(float value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

/*
 * Insert node in sorted order (insertion sort within bucket)
 */
Node* insertSorted(Node *head, float value) {
    Node *newNode = createNode(value);
    
    // If list is empty or new value should be first
    if (head == NULL || head->value >= value) {
        newNode->next = head;
        return newNode;
    }
    
    // Find the position to insert
    Node *current = head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

/*
 * Bucket Sort for floating point numbers in [0, 1)
 */
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    Node **buckets = (Node **)calloc(n, sizeof(Node *));
    
    // Put elements into respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(n * arr[i]);
        // Handle edge case where arr[i] == 1.0
        if (bucketIndex >= n) bucketIndex = n - 1;
        buckets[bucketIndex] = insertSorted(buckets[bucketIndex], arr[i]);
    }
    
    // Concatenate all buckets into arr
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node *current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->value;
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    free(buckets);
}

/*
 * Bucket Sort for integers
 * Normalizes integers to [0, 1) range and uses the same algorithm
 */
void bucketSortInt(int arr[], int n, int maxVal) {
    if (n <= 0 || maxVal <= 0) return;
    
    // Create n empty buckets
    Node **buckets = (Node **)calloc(n, sizeof(Node *));
    
    // Put elements into respective buckets
    for (int i = 0; i < n; i++) {
        // Normalize to [0, n) range
        int bucketIndex = (int)((long long)arr[i] * n / (maxVal + 1));
        if (bucketIndex >= n) bucketIndex = n - 1;
        if (bucketIndex < 0) bucketIndex = 0;
        buckets[bucketIndex] = insertSorted(buckets[bucketIndex], (float)arr[i]);
    }
    
    // Concatenate all buckets into arr
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node *current = buckets[i];
        while (current != NULL) {
            arr[index++] = (int)current->value;
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    free(buckets);
}
