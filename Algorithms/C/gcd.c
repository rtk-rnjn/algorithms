#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int n1 = 10;
    int n2 = 15;

    int gcd_result = gcd(n1, n2);

    printf("GCD of %d and %d is %d\n", n1, n2, gcd_result);

    return 0;
}
