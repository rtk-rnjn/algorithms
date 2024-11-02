#include <stdio.h>
#include <string.h>

int search_pattern(char *text, char *pattern, int expected_text_len, int expected_pattern_len)
{
    int text_length = (int)strnlen(text, expected_text_len);
    int pattern_length = (int)strnlen(pattern, expected_pattern_len);

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

    int text_len = 20;
    int pattern_len = 4;

    int index = search_pattern(text, pattern, text_len, pattern_len);

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
