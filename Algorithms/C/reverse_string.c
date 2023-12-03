#include <stdio.h>

void reverse_string(char* str, int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char str[] = "Hello World";
    int len = sizeof(str) / sizeof(str[0]) - 1;  // -1 to exclude NULL terminator

    reverse_string(str, len);
    printf("%s\n", str);

    return 0;
}
