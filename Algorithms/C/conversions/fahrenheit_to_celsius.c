#include <stdio.h>

float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

int main()
{
    float fahrenheit = 98.6F;
    float celsius = fahrenheit_to_celsius(fahrenheit);
    printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
    return 0;
}
