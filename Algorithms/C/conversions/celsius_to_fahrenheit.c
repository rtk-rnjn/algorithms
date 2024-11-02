#include <stdio.h>

float celsius_to_fahrenheit(float celsius)
{
    return celsius * 9 / 5 + 32;
}

int main()
{
    float celsius = 37;
    float fahrenheit = celsius_to_fahrenheit(celsius);
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
    return 0;
}
