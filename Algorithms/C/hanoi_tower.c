#include <stdio.h>

int G_COUNT = 0;

void hanoi_tower(int n, char from, char to, char aux) {
    if (n == 1) {
        G_COUNT++;
        printf("%02d Move disk 1 from %c to %c\n", G_COUNT, from, to);
        return;
    }

    hanoi_tower(n - 1, from, aux, to);
    G_COUNT++;
    printf("%02d Move disk %d from %c to %c\n", G_COUNT, n, from, to);
    hanoi_tower(n - 1, aux, to, from);
}

int main() {
    int n = 4;
    hanoi_tower(n, 'A', 'C', 'B');
    return 0;
}
