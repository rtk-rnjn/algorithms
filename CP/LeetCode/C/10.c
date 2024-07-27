// 10. Regex Matching

#include <stdbool.h>
#include <stdio.h>

bool isMatch(char *s, char *p)
{
    if (*p == '\0')
    {
        return *s == '\0';
    }

    bool firstMatch = *s && (*s == *p || *p == '.');

    if (*(p + 1) == '*')
    {
        return isMatch(s, p + 2) || (firstMatch && isMatch(s + 1, p));
    }
    else
    {
        return firstMatch && isMatch(s + 1, p + 1);
    }
}

int main()
{
    char s[] = "aaaaaaa";
    char p[] = "a*";
    printf("%d\n", isMatch(s, p));
    return 0;
}