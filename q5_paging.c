#include <stdio.h>

#define P 4

int main(void) {
    int frame[P], size, addr, page, off;

    printf("Page size: ");
    if (scanf("%d", &size) != 1 || size < 1) return 1;
    printf("Frame number for each of %d pages: ", P);
    for (int i = 0; i < P; i++)
        if (scanf("%d", &frame[i]) != 1 || frame[i] < 0) return 1;

    printf("Logical address (0-%d): ", P * size - 1);
    if (scanf("%d", &addr) != 1 || addr < 0 || addr >= P * size) return 1;

    page = addr / size;
    off = addr % size;
    printf("Page %d, offset %d, physical address %d\n",
           page, off, frame[page] * size + off);
    return 0;
}
