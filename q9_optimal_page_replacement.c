#include <stdio.h>

int main(void) {
    int p[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
    int f[3] = {-1,-1,-1}, faults = 0;

    for (int i = 0; i < 13; i++) {
        int k = -1;
        for (int j = 0; j < 3; j++)
            if (f[j] == p[i]) k = j;
        if (k < 0) {
            int far = -1;
            faults++;
            for (int j = 0; j < 3; j++) {
                int next = 13;
                if (f[j] < 0) { k = j; break; }
                for (int x = i + 1; x < 13; x++)
                    if (p[x] == f[j]) { next = x; break; }
                if (next > far) { far = next; k = j; }
            }
            f[k] = p[i];
        }
        printf("%d: %d %d %d\n", p[i], f[0], f[1], f[2]);
    }
    printf("Page faults: %d\n", faults);
    return 0;
}
