#include <iostream>
#include <string>
using namespace std;

int reverse_string(string str, int size)
{
    char temp;

    for (int i = 0; i < size / 2; i++)
    {
        temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }

    return 0;
}

int main()
{
    string str = "Hello World";

    int size = sizeof(str) / sizeof(str[0]) - 1;

    reverse_string(str, size);
    cout << str << endl;

    return 0;
}