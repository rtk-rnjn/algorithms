#include <stdio.h>

int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main () {
    int n = 12345;
    printf("Sum of digits of %d is %d\n", n, sum_of_digits(n));
    return 0;
}
