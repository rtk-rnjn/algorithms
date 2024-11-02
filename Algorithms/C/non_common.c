#include <stdio.h>

void findNonCommonElements(int arr1[], int m, int arr2[], int n)
{
    int i = 0;
    int j = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            printf("%d ", arr1[i]);
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            printf("%d ", arr2[j]);
            j++;
        }
        else
        {
            // Both elements are equal, move both pointers
            i++;
            j++;
        }
    }

    // Print remaining elements of the arrays if any
    while (i < m)
    {
        printf("%d ", arr1[i]);
        i++;
    }

    while (j < n)
    {
        printf("%d ", arr2[j]);
        j++;
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int m = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr2) / sizeof(arr2[0]);

    printf("Non-common elements: ");
    findNonCommonElements(arr1, m, arr2, n);

    return 0;
}
