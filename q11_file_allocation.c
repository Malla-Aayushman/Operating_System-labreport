#include <stdio.h>

int main(void) {
    int blocks[] = {4, 9, 14, 20};

    printf("Sequential: ");
    for (int i = 0; i < 4; i++) printf("%d ", 4 + i);

    printf("\nIndexed (block 25): ");
    for (int i = 0; i < 4; i++) printf("%d ", blocks[i]);

    printf("\nLinked: ");
    for (int i = 0; i < 4; i++) printf("%d -> ", blocks[i]);
    puts("NULL");
    return 0;
}
