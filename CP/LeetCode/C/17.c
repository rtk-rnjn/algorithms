// 17. Letter Combinations of a Phone Number

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char **letterCombinations(const char *digits, int *returnSize)
{
    if (digits[0] == '\0')
    {
        *returnSize = 0;
        return NULL;
    }
    int len = 1;
    for (int i = 0; digits[i] != '\0'; i++)
    {
        len *= 4;
    }
    char **result = (char **)malloc(len * sizeof(char *));
    int k = 0;
    for (int i = 0; digits[i] != '\0'; i++)
    {
        int digit = digits[i] - '0';
        if (i == 0)
        {
            for (int j = 0; letters[digit][j] != '\0'; j++)
            {
                result[k] = (char *)malloc(2 * sizeof(char));
                result[k][0] = letters[digit][j];
                result[k][1] = '\0';
                k++;
            }
        }
        else
        {
            int count = k;
            for (int j = 0; j < count; j++)
            {
                for (int l = 0; letters[digit][l] != '\0'; l++)
                {
                    result[k] = (char *)malloc((strlen(result[j]) + 2) * sizeof(char));
                    strcpy(result[k], result[j]);
                    result[k][strlen(result[j])] = letters[digit][l];
                    result[k][strlen(result[j]) + 1] = '\0';
                    k++;
                }
            }
        }
    }
    *returnSize = k;
    return result;
}

int main()
{
    const char *digits = "23";
    int returnSize;
    char **result = letterCombinations(digits, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", result[i]);
        free(result[i]);
        result[i] = NULL;
    }

    free(result);
    result = NULL;

    return 0;
}
