#include <iostream>

using namespace std;

int sum_of_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    int number = 12345;

    int result = sum_of_digits(number);
    cout << "Sum of digit: " << result << endl;

    return 0;
}
