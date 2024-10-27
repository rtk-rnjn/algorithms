#include <stdio.h>

// int lcm(int a, int b)
// {
//     static int common = 1;
//     if (common % a == 0 && common % b == 0)
//     {
//         return common;
//     }
//     common++;
//     lcm(a, b);
//     return common;
// }

// ---

// int gcd(int a, int b)
// {
//     if (b == 0)
//     {
//         return a;
//     }
//     return gcd(b, a % b);
// }

// int lcm(int a, int b)
// {
//     if (a > b)
//     {
//         return a / gcd(a, b) * b;
//     }

//     return b / gcd(a, b) * a;
// }

// ---

int lcm(int a, int b)
{
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    
    int res = 0;

    for (int i = 1; i < max; i++)
    {
        if (min * i % max == 0)
        {
            res = min * i;
            break;
        }
    }
    return res;
}

int main()
{
    int n1 = 10;
    int n2 = 15;

    int lcm_result = lcm(n1, n2);

    printf("LCM of %d and %d is %d\n", n1, n2, lcm_result);

    return 0;
}
