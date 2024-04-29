#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compute_LSP_array(const char *pattern, int pattern_length, int *LSP)
{
    int length = 0;
    LSP[0] = 0;

    for (int i = 1; i < pattern_length; i++)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            LSP[i] = length;
        }
        else
        {
            if (length != 0)
            {
                length = LSP[length - 1];
                i--;
            }
            else
            {
                LSP[i] = 0;
            }
        }
    }
}

int search_pattern(char *text, char *pattern)
{
    int text_length = (int)strlen(text);
    int pattern_length = (int)strlen(pattern);

    int *LSP = (int *)malloc(pattern_length * sizeof(int));
    compute_LSP_array(pattern, pattern_length, LSP);

    int i = 0;
    int j = 0;

    while (i < text_length)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == pattern_length)
        {
            free(LSP);
            return i - j;
        }

        if (i < text_length && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = LSP[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    free(LSP);
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
