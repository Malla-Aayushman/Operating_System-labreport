#include <stdio.h>

#define N 20
#define K 4

int main(void) {
    int disk[N] = {0}, data[K] = {2, 7, 11, 15}, start = 3;
    int next[N];

    puts("Sequential allocation:");
    for (int i = 0; i < K; i++) {
        disk[start + i] = 1;
        printf("%d ", start + i);
    }

    for (int i = 0; i < N; i++) disk[i] = 0;
    disk[19] = 1;
    puts("\nIndexed allocation (index block 19):");
    for (int i = 0; i < K; i++) {
        disk[data[i]] = 1;
        printf("%d ", data[i]);
    }

    for (int i = 0; i < N; i++) {
        disk[i] = 0;
        next[i] = -1;
    }
    for (int i = 0; i < K; i++) disk[data[i]] = 1;
    for (int i = 0; i < K - 1; i++) next[data[i]] = data[i + 1];

    puts("\nLinked allocation:");
    for (int b = data[0]; b != -1; b = next[b])
        printf("%d -> ", b);
    puts("NULL");
    return 0;
}
