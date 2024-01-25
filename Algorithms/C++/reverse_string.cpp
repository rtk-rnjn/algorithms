#include <iostream>
#include <string>

using namespace std;

void reverse_string(string &str)
{
    int size = str.size();
    char temp;

    for (int i = 0; i < size / 2; i++)
    {
        temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }
}

int main()
{
    string str = "Hello World";

    reverse_string(str);
    cout << str << endl;

    return 0;
}
