// 65. Valid Numbers

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isNumber(char *s) // NOLINT
{
    int i = 0;
    int len = (int)strlen(s);
    int dot = 0;
    int e = 0;
    int num = 0;
    int num_after_e = 0;
    int space = 0;
    while (s[i] == ' ')
    {
        i++;
        space++;
    }
    if (space == len)
    {
        return false;
    }
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    while (i < len)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            i++;
            num = 1;
            num_after_e = 1;
        }
        else if (s[i] == '.')
        {
            if (dot || e)
            {
                return false;
            }
            dot = 1;
            i++;
        }
        else if (s[i] == 'e')
        {
            if (e || !num)
            {
                return false;
            }
            e = 1;
            num_after_e = 0;
            i++;
            if (s[i] == '+' || s[i] == '-')
            {
                i++;
            }
        }
        else if (s[i] == ' ')
        {
            i++;
            while (s[i] == ' ')
            {
                i++;
            }
            if (i < len)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return num && num_after_e;
}

int main()
{
    char *s = "0.1.e10";
    printf("%d\n", isNumber(s));
    return 0;
}
