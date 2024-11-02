#include <stdio.h>
#include <stdlib.h>

char *int_to_string(int n)
{
    int length = snprintf(NULL, 0, "%d", n);
    char *str = (char *)malloc(length + 1);
    snprintf(str, length + 1, "%d", n);
    return str;
}

int main()
{
    int n = 12345;
    char *str = int_to_string(n);
    printf("%s\n", str);
    free(str);
    return 0;
}
