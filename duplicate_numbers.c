#include <stdio.h>

void duplicate_numbers(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > 1) {
            printf("%d appears %d times\n", arr[i], count);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 6, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    duplicate_numbers(arr, len);

    return 0;
}
