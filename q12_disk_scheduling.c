#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int x = a[i]; a[i] = a[j]; a[j] = x;
            }
}

int main(void) {
    int r[20], l[20], h[20], n, head, disk, nl = 0, nh = 0;
    int fcfs = 0, scan = 0, look = 0, clook = 0, cur;

    printf("Disk size, request count, requests, head: ");
    scanf("%d%d", &disk, &n);
    if (disk < 2 || n < 1 || n > 20) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
        if (r[i] < 0 || r[i] >= disk) return 1;
    }
    scanf("%d", &head);
    if (head < 0 || head >= disk) return 1;

    cur = head;
    for (int i = 0; i < n; i++) {
        fcfs += abs(cur - r[i]);
        cur = r[i];
        if (r[i] < head) l[nl++] = r[i];
        else h[nh++] = r[i];
    }

    sort(l, nl);
    sort(h, nh);
    cur = head;
    for (int i = 0; i < nh; i++) {
        scan += abs(cur - h[i]);
        look += abs(cur - h[i]);
        clook += abs(cur - h[i]);
        cur = h[i];
    }

    if (nl) {
        scan += abs(cur - (disk - 1));
        cur = disk - 1;
        for (int i = nl - 1; i >= 0; i--) {
            scan += abs(cur - l[i]);
            cur = l[i];
        }

        cur = nh ? h[nh - 1] : head;
        look += abs(cur - l[nl - 1]);
        for (int i = nl - 1; i > 0; i--)
            look += abs(l[i] - l[i - 1]);

        cur = nh ? h[nh - 1] : head;
        clook += abs(cur - l[0]);
        for (int i = 1; i < nl; i++)
            clook += abs(l[i] - l[i - 1]);
    } else if (nh) {
        scan += abs(cur - (disk - 1));
    }

    printf("FCFS %d\nSCAN %d\nLOOK %d\nC-LOOK %d\n",
           fcfs, scan, look, clook);
    return 0;
}
