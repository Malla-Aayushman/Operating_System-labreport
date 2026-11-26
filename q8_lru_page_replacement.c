#include <stdio.h>

int main(void) {
    int p[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
    int f[3] = {-1,-1,-1}, used[3] = {0}, faults = 0, time = 0;

    for (int i = 0; i < 13; i++) {
        int k = -1;
        for (int j = 0; j < 3; j++)
            if (f[j] == p[i]) k = j;
        if (k < 0) {
            faults++;
            k = 0;
            for (int j = 0; j < 3; j++) {
                if (f[j] < 0) { k = j; break; }
                if (used[j] < used[k]) k = j;
            }
            f[k] = p[i];
        }
        used[k] = ++time;
        printf("%d: %d %d %d\n", p[i], f[0], f[1], f[2]);
    }
    printf("Page faults: %d\n", faults);
    return 0;
}
