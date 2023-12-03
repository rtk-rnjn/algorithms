#include <stdio.h>

void reverse_string_recursive(char* str, int len) {
    if (len == 0) {
        return;
    }
    if (len == 1) {
        return;
    }

    char temp = str[0];
    str[0] = str[len - 1];
    str[len - 1] = temp;

    reverse_string_recursive(str + 1, len - 2);
}

int main() {
    char str[] = "Hello World";
    int len = sizeof(str) / sizeof(str[0]) - 1;  // -1 to exclude NULL terminator

    reverse_string_recursive(str, len);
    printf("%s\n", str);

    return 0;
}
