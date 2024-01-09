#include <iostream>

using namespace std;

int sum(int number)
{
    if (number < 10)
    {
        return number;
    }

    return number % 10 + sum(number / 10);
}

int main()
{
    int number = 123;

    cout << sum(number);
    return 0;
}
