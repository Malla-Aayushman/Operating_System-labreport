#include <stdio.h>

int main(void) {
    int a[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    int m[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int v[3] = {3,3,2}, done[5] = {0}, count = 0;

    while (count < 5) {
        int found = 0;
        for (int i = 0; i < 5; i++) {
            int j;
            if (done[i]) continue;
            for (j = 0; j < 3; j++)
                if (m[i][j] - a[i][j] > v[j]) break;
            if (j == 3) {
                for (j = 0; j < 3; j++) v[j] += a[i][j];
                printf("P%d ", i);
                done[i] = found = 1;
                count++;
            }
        }
        if (!found) {
            puts("\nUnsafe state");
            return 0;
        }
    }
    puts("\nSafe state");
    return 0;
}
