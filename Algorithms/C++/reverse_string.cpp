#include <iostream>

using namespace std;

int reverse_string(char *string, int size)
{
    char temp;

    for (int i = 0; i < size / 2; i++)
    {
        temp = string[i];
        string[i] = string[size - i - 1];
        string[size - i - 1] = temp;
    }

    return 0;
}

int main()
{
    char string[] = "Hello World!";
    int size = sizeof(string) / sizeof(string[0]) - 1; // -1 to exclude NULL

    reverse_string(string, size);
    cout << string;

    return 0;
}