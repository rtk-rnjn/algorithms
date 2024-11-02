#include <stdio.h>

void print_factorial(int n)
{
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    printf("%d\n", fact);
}

int main()
{
    int n = 5;
    print_factorial(n);

    return 0;
}
