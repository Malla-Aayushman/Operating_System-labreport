#include <stdio.h>

void fit(int block[], int n, int p[], int m, int type) {
    int left[10];

    for (int i = 0; i < n; i++) left[i] = block[i];
    for (int i = 0; i < m; i++) {
        int k = -1;
        for (int j = 0; j < n; j++)
            if (left[j] >= p[i] &&
                (k < 0 || (type == 1 && left[j] < left[k]) ||
                 (type == 2 && left[j] > left[k]))) {
                k = j;
                if (!type) break;
            }
        printf("P%d (%d): ", i + 1, p[i]);
        if (k < 0) puts("Not allocated");
        else {
            printf("Block %d\n", k + 1);
            left[k] -= p[i];
        }
    }
}

int main(void) {
    int b[] = {100, 500, 200, 300, 600};
    int p[] = {212, 417, 112, 426};

    puts("First fit"); fit(b, 5, p, 4, 0);
    puts("Best fit");  fit(b, 5, p, 4, 1);
    puts("Worst fit"); fit(b, 5, p, 4, 2);
    return 0;
}
