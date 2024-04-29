#include <stdio.h>
#include <string.h>

int search_pattern(char *text, char *pattern)
{
    int text_length = (int)strlen(text);
    int pattern_length = (int)strlen(pattern);

    for (int i = 0; i <= text_length - pattern_length; i++)
    {
        int j;

        for (j = 0; j < pattern_length; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }

        if (j == pattern_length)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char text[] = "CAABAACAADAABAAABAA";
    char pattern[] = "AABA";

    int index = search_pattern(text, pattern);

    if (index != -1)
    {
        printf("Pattern found at index %d\n", index);
    }
    else
    {
        printf("Pattern not found\n");
    }

    return 0;
}
