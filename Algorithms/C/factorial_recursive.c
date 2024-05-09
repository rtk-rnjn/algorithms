#include <stdio.h>
#include <stdlib.h>

int *memo;

int factorial(int n)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }

    if (n == 0)
    {
        memo[n] = 1;
    }
    else
    {
        memo[n] = n * factorial(n - 1);
    }

    return memo[n];
}

int main()
{
    int n = 5;
    memo = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }

    printf("%d\n", factorial(n));

    free(memo);

    return 0;
}
