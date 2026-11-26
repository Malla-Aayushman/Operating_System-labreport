#include <stdio.h>

void show(int n, int w[], int t[]) {
    printf("\nProcess  Waiting  Turnaround\n");
    for (int i = 0; i < n; i++)
        printf("P%d       %d        %d\n", i + 1, w[i], t[i]);
}

int main(void) {
    int n, b[10], w[10], t[10], r[10], order[10], q, time = 0, done = 0;

    printf("Process count (max 10): ");
    scanf("%d", &n);
    if (n < 1 || n > 10) return 1;
    for (int i = 0; i < n; i++) {
        printf("Burst P%d: ", i + 1);
        if (scanf("%d", &b[i]) != 1 || b[i] < 1) return 1;
        r[i] = b[i];
        order[i] = i;
    }

    printf("Time quantum: ");
    scanf("%d", &q);
    if (q < 1) return 1;

    puts("\nFCFS");
    for (int i = 0; i < n; i++) {
        w[i] = time;
        t[i] = time += b[i];
    }
    show(n, w, t);

    puts("\nSJF");
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (b[order[j]] < b[order[i]]) {
                int x = order[i]; order[i] = order[j]; order[j] = x;
            }
    time = 0;
    for (int i = 0; i < n; i++) {
        int p = order[i];
        w[p] = time;
        t[p] = time += b[p];
    }
    show(n, w, t);

    puts("\nRound Robin");
    time = 0;
    while (done < n)
        for (int i = 0; i < n; i++)
            if (r[i] > 0) {
                int x = r[i] < q ? r[i] : q;
                time += x;
                r[i] -= x;
                if (!r[i]) {
                    t[i] = time;
                    w[i] = time - b[i];
                    done++;
                }
            }
    show(n, w, t);
    return 0;
}
