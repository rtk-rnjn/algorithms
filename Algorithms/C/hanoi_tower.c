#include <stdio.h>

void hanoi_tower(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    hanoi_tower(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi_tower(n - 1, aux, to, from);
}

int main()
{
    int n = 4;
    hanoi_tower(n, 'A', 'C', 'B');
    return 0;
}
