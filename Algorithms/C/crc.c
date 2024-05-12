#include <stdio.h>
#include <string.h>

#define WIDTH (8 * sizeof(unsigned long))

unsigned long crc32(const unsigned char *message)
{
    int i;
    int j;
    unsigned long crc;
    unsigned long mask;

    i = 0;
    crc = 0xFFFFFFFF;
    while (message[i] != 0)
    {
        unsigned long byte = message[i];
        crc = crc ^ byte;
        for (j = 7; j >= 0; j--)
        {
            mask = -(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
        }
        i = i + 1;
    }
    return ~crc;
}

int main()
{
    const unsigned char text[] = "123456789";
    unsigned long result = crc32(text);
    printf("CRC32: %lu\n", result);
    return 0;
}
