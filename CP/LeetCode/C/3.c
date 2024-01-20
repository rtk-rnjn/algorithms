// 3. Longest Substring Without Repeating Characters
#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char *s)
{
    int i = 0, j = 0, max = 0;
    int hash[128] = {0};
    while (s[j] != '\0')
    {
        if (hash[(unsigned char)s[j]] > i)
        {
            i = hash[(unsigned char)s[j]];
        }
        hash[(unsigned char)s[j]] = j + 1;
        if (j - i + 1 > max)
        {
            max = j - i + 1;
        }
        j++;
    }
    return max;
}

int main()
{
    char s[] = "abcabcbb";
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}
