// 38. Count and Say

#include <stdio.h>
#include <stdlib.h>

char *countAndSay(int n)
{
    char *result = (char *)malloc(5000 * sizeof(char));
    result[0] = '1';
    result[1] = '\0';

    int count;
    char temp[5000];

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        int k = 0;
        while (result[j] != '\0')
        {
            count = 1;
            while (result[j] == result[j + 1])
            {
                count++;
                j++;
            }
            temp[k++] = (char)(count + '0');
            temp[k++] = result[j];
            j++;
        }
        temp[k] = '\0';
        for (j = 0; temp[j] != '\0'; j++)
        {
            result[j] = temp[j];
        }
        result[j] = '\0';
    }

    return result;
}

int main()
{
    int n = 4;

    char *result = countAndSay(n);
    printf("%s\n", result);
    free(result);

    return 0;
}