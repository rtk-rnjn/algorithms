// 6. Zigzag Conversion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }

    int len = (int)strlen(s);
    char *res = (char *)malloc(len + 1);
    int index = 0;
    int step = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = i; j < len; j += step)
        {
            res[index++] = s[j];
            if (i > 0 && i < numRows - 1)
            {
                int t = j + step - 2 * i;
                if (t < len)
                {
                    res[index++] = s[t];
                }
            }
        }
    }
    res[index] = '\0';
    return res;
}

int main()
{
    char s[] = "PAYPALISHIRING";
    int numRows = 3;
    char *res = convert(s, numRows);
    printf("%s\n", res);
    free(res);
    return 0;
}