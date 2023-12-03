#include <stdio.h>

int smallest_element_recursive(int* arr, int len) {
    if (len == 0) {
        return 0;
    }
    if (len == 1) {
        printf("Smallest element is %d\n", arr[0]);
        return arr[0];
    }

    int smallest = smallest_element_recursive(arr + 1, len - 1);
    return arr[0] < smallest ? arr[0] : smallest;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    smallest_element_recursive(arr, len);

    return 0;
}