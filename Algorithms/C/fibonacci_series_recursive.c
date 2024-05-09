#include <stdio.h>
#include <stdlib.h>

int *memo;

int fib(int n)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }

    if (n <= 1)
    {
        memo[n] = n;
    }
    else
    {
        memo[n] = fib(n - 1) + fib(n - 2);
    }

    return memo[n];
}

void print_series(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", fib(i));
    }
}

int main()
{
    int n = 10;

    memo = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        memo[i] = -1;
    }

    print_series(n);

    free(memo);

    return 0;
}
