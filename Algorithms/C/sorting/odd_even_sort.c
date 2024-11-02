#include <stdio.h>

void odd_even_sort(int *array, int array_size);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void odd_even_sort(int *array, int array_size)
{
    int sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        for (int i = 1; i < array_size - 1; i += 2)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                sorted = 0;
            }
        }

        for (int i = 0; i < array_size - 1; i += 2)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                sorted = 0;
            }
        }
    }
}

int main()
{
    int array[] = {5, 2, 4, 6, 1, 3};
    int array_size = sizeof(array) / sizeof(array[0]);

    odd_even_sort(array, array_size);

    printf("Sorted array: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
