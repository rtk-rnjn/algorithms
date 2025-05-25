#include <stdio.h>

float fast_inverse_square_root(float value)
{
    float half_value = value * 0.5F;
    const float three_halves = 1.5F;

    union {
        float f;
        unsigned int i;
    } conv;

    conv.f = value;
    conv.i = 0x5f3759df - (conv.i >> 1);
    float approx = conv.f;

    approx = approx * (three_halves - (half_value * approx * approx));

    return approx;
}

int main()
{
    float input_value = 4.0F;
    float inv_sqrt = fast_inverse_square_root(input_value);
    printf("Inverse square root of %f is %f\n", input_value, inv_sqrt);
    return 0;
}
