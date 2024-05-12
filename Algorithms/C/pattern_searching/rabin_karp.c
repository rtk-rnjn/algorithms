#include <stdio.h>
#include <string.h>

#define d 26

int search_pattern(const char *text, const char *pattern, int q, int expected_text_len, int expected_pattern_len)
{
    int pattern_length = (int)strnlen(pattern, expected_pattern_len);
    int text_length = (int)strnlen(text, expected_text_len);

    int i;
    int j;

    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < pattern_length - 1; i++)
    {
        h = (h * d) % q;
    }

    for (i = 0; i < pattern_length; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= text_length - pattern_length; i++)
    {
        if (p == t)
        {
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

        if (i < text_length - pattern_length)
        {
            t = (d * (t - text[i] * h) + text[i + pattern_length]) % q;
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }

    return -1;
}

int main()
{
    char text[] = "CAABCAAABAACAADAABAAABAA";
    char pattern[] = "AABAA";

    int text_len = 25;
    int pattern_len = 5;

    int q = 101; // A prime number
    int index = search_pattern(text, pattern, q, text_len, pattern_len);

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
