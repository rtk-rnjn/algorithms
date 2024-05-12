#include <stdio.h>

float inverse_squre_root(float number)
{
    long i;
    float x2;
    float y;

    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long *)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));

    return y;
}

int main()
{
    float number = 4.0F;
    float result = inverse_squre_root(number);
    printf("Inverse square root of %f is %f\n", number, result);
    return 0;
}
