#include <stdio.h>

void pair_product(int *arr, int len, int product)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        { // j = i + 1 to avoid duplicate pairs
            if (arr[i] * arr[j] == product)
            {
                printf("%d * %d = %d\n", arr[i], arr[j], product);
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    int product = 6;

    pair_product(arr, len, product);

    return 0;
}
