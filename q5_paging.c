#include <stdio.h>

int main(void) {
    int pageTable[] = {5, 2, 8, 1};
    int address, page, offset, pageSize = 1000;

    printf("Logical address (0-3999): ");
    scanf("%d", &address);
    if (address < 0 || address >= 4000) return 1;

    page = address / pageSize;
    offset = address % pageSize;
    printf("Page %d, offset %d, physical address %d\n",
           page, offset, pageTable[page] * pageSize + offset);
    return 0;
}
