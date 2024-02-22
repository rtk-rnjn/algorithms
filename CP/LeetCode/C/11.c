// 11. Container With Most Water

#include <stdio.h>

int maxArea(const int *height, int heightSize)
{
    int max = 0;
    int i = 0;
    int j = heightSize - 1;
    while (i < j)
    {
        int h = height[i] < height[j] ? height[i] : height[j];
        int area = h * (j - i);
        if (area > max)
        {
            max = area;
        }
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return max;
}

int main()
{
    const int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    printf("%d\n", maxArea(height, heightSize));
    return 0;
}
