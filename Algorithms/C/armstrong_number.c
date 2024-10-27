#include <stdio.h>
#include <stdbool.h>

int power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

int order(int x)
{
    int n = 0;
    while (x != 0)
    {
        n++;
        x /= 10;
    }
    return n;
}

bool is_armstrong(int number)
{
    int n = order(number);
    int temp = number;
    int sum = 0;
    while (temp != 0)
    {
        int remainder = temp % 10;
        sum += power(remainder, n);
        temp /= 10;
    }
    return sum == number;
}

int main()
{
    int number = 153;
    if (is_armstrong(number))
    {
        printf("%d is an Armstrong number.\n", number);
    }
    else
    {
        printf("%d is not an Armstrong number.\n", number);
    }
}
