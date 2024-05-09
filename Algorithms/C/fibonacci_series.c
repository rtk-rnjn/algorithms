#include <stdio.h>

void print_series(int n)
{
    int a = 0;
    int b = 1;

    int temp;

    while (n-- > 0)
    {
        printf("%d\n", a);
        temp = a;
        a = b;
        b = temp + b;
    }
}

int main()
{
    int n = 10;
    print_series(n);

    return 0;
}
