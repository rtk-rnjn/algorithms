#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_series(int n)
{
    int a = 0;
    int b = 1;

    while (n-- > 0)
    {
        printf("%d\n", a);
        swap(&a, &b);
    }
}

int main()
{
    int n = 10;
    print_series(n);

    return 0;
}
