#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void bad_character_heuristic(const char *pattern, int pattern_length, int *bad_character_shift, int NO_OF_CHARS)
{
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        bad_character_shift[i] = -1;
    }

    for (int i = 0; i < pattern_length; i++)
    {
        bad_character_shift[(int)pattern[i]] = i;
    }
}

int search_pattern(const char *text, const char *pattern, int expected_text_length, int expected_pattern_length)
{
    int text_length = (int)strnlen(text, expected_text_length);
    int pattern_length = (int)strnlen(pattern, expected_pattern_length);

    int NO_OF_CHARS = 256;
    int *bad_character_shift = (int *)malloc(NO_OF_CHARS * sizeof(int));

    bad_character_heuristic(pattern, pattern_length, bad_character_shift, NO_OF_CHARS);

    int s = 0;
    while (s <= (text_length - pattern_length))
    {
        int j = pattern_length - 1;

        while (j >= 0 && pattern[j] == text[s + j])
        {
            j--;
        }

        if (j < 0)
        {
            free(bad_character_shift);
            return s;
        }

        s += max(1, j - bad_character_shift[(int)text[s + j]]);
    }

    free(bad_character_shift);

    return -1;
}

int main()
{
    char text[] = "CAABAACAADAABAAABAA";
    char pattern[] = "AABA";

    int text_length = 19;
    int pattern_length = 4;

    int index = search_pattern(text, pattern, text_length, pattern_length);

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
