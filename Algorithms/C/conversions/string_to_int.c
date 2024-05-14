#include <stdio.h>
#include <stdlib.h>

int string_to_int(char *str)
{
    int n = 0;
    int sign = 1;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str)
    {
        n = n * 10 + (*str - '0');
        str++;
    }
    return n * sign;
}

int main()
{
    char str[] = "-12345";
    int n = string_to_int(str);
    printf("%d\n", n);
    return 0;
}
