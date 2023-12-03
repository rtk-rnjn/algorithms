#include <stdio.h>

void smallest_element(int* arr, int len, int* smallest, int* index) {
    *smallest = arr[0];
    *index = 0;
    for (int i = 1; i < len; i++) {
        if (arr[i] < *smallest) {
            *smallest = arr[i];
            *index = i;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    int smallest, index;

    smallest_element(arr, len, &smallest, &index);
    printf("Smallest element is %d at index %d\n", smallest, index);

    return 0;
}
