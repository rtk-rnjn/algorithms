#include <stdio.h>

void move_duplicates_to_front(int arr[], int n) {
    int unique_index = 0;

    for (int i = 0; i < n; i++) {
        // Check if the current element is not a duplicate
        int is_duplicate = 0;
        for (int j = 0; j < unique_index; j++) {
            if (arr[i] == arr[j]) {
                is_duplicate = 1;
                break;
            }
        }

        // If not a duplicate, move it to the unique_index position
        if (!is_duplicate) {
            arr[unique_index] = arr[i];
            unique_index++;
        }
    }
}

int main() {
    int arr[] = {3, 6, 8, 3, 2, 7, 6, 5, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    move_duplicates_to_front(arr, n);

    printf("\nArray after moving duplicates to the front: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
