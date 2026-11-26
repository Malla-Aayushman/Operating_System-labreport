#include <stdio.h>
#include <stdlib.h>

#define N 20

void sort(int a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int x = a[i]; a[i] = a[j]; a[j] = x;
            }
}

void show(const char *name, int a[], int n, int head) {
    int total = 0, cur = head;

    printf("%s: %d", name, head);
    for (int i = 0; i < n; i++) {
        total += abs(cur - a[i]);
        cur = a[i];
        printf(" -> %d", cur);
    }
    printf("  Total: %d\n", total);
}

int main(void) {
    int r[N], l[N], h[N], f[N], s[N + 1], look[N], c[N];
    int n, disk, head, nl = 0, nh = 0, ns = 0, nc = 0;

    puts("Direction: upward");
    printf("Disk size and request count: ");
    if (scanf("%d%d", &disk, &n) != 2 || disk < 2 || n < 1 || n > N) return 1;
    printf("Requests: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &r[i]) != 1 || r[i] < 0 || r[i] >= disk) return 1;
        if (r[i] < 0) return 1;
    }
    printf("Initial head position: ");
    if (scanf("%d", &head) != 1 || head < 0 || head >= disk) return 1;

    for (int i = 0; i < n; i++) {
        f[i] = r[i];
        if (r[i] < head) l[nl++] = r[i];
        else h[nh++] = r[i];
    }
    sort(l, nl);
    sort(h, nh);
    show("FCFS", f, n, head);

    for (int i = 0; i < nh; i++) s[ns++] = h[i];
    s[ns++] = disk - 1;
    for (int i = nl - 1; i >= 0; i--) s[ns++] = l[i];
    show("SCAN", s, ns, head);

    for (int i = 0; i < nh; i++) look[i] = h[i];
    int m = nh;
    for (int i = nl - 1; i >= 0; i--) look[m++] = l[i];
    show("LOOK", look, m, head);

    for (int i = 0; i < nh; i++) c[nc++] = h[i];
    for (int i = 0; i < nl; i++) c[nc++] = l[i];
    show("C-LOOK", c, nc, head);
    return 0;
}
