#include <stdio.h>

int main(void) {
    int p[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
    int f[3] = {-1,-1,-1}, faults = 0, next = 0;

    for (int i = 0; i < 13; i++) {
        int hit = 0;
        for (int j = 0; j < 3; j++)
            if (f[j] == p[i]) hit = 1;
        if (!hit) {
            f[next] = p[i];
            next = (next + 1) % 3;
            faults++;
        }
        printf("%d: %d %d %d %s\n", p[i], f[0], f[1], f[2],
               hit ? "hit" : "fault");
    }
    printf("Page faults: %d\n", faults);
    return 0;
}
