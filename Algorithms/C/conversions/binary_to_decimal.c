#include <stdio.h>
#include <math.h>
#include <inttypes.h>

// uint64_t is an unsigned 64-bit integer

uint64_t binary_to_decimal(uint64_t n)
{
    uint64_t decimal = 0;
    uint64_t base = 1;
    uint64_t temp = n;
    while (temp > 0)
    {
        uint64_t last_digit = temp % 10;
        temp = temp / 10;
        decimal += last_digit * base;
        base = base * 2;
    }
    return decimal;
}

int main()
{
    uint64_t n = 1010;
    printf("Binary: %" PRIu64 "\n", n);
    printf("Decimal: %" PRIu64 "\n", binary_to_decimal(n));
    return 0;
}