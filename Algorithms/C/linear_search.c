#include <stdio.h>
#include <stdlib.h>

int linear_search(int *arr, int target, int length)
{
    for (int i = 0; i < arr[length]; i++) {
            if (arr[i] == target) {
                return i;
            }
        
        }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int target = 3;
    int length = sizeof(arr) / sizeof(arr[0]);
    int result = linear_search(arr, target, length);
    printf("%d", result);
    return 0;
   
}


