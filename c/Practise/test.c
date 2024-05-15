#include <stdio.h>

// Function to swap two elements in an array
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate permutations using recursion
void generatePermutations(char arr[], int start, int end) {
    if (start == end) {
        // Print the current permutation
        for (int i = 0; i <= end; i++) {
            printf("%c ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            // Swap the current element with the element at index 'start'
            swap(&arr[start], &arr[i]);

            // Recursively generate permutations for the remaining elements
            generatePermutations(arr, start + 1, end);

            // Undo the swap to backtrack and try the next possibility
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    // Example array
    char arr[] = {'A', 'B', 'C', 'D'};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Permutations:\n");
    generatePermutations(arr, 0, n - 1);

    return 0;
}
