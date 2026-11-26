#include <stdio.h>

int main(void) {
    const char *single[] = {"notes.txt", "report.txt"};
    struct { const char *user, *file[2]; } two[] = {
        {"Asha", {"notes.txt", "os.c"}},
        {"Ravi", {"notes.txt", "db.c"}}
    };
    struct { const char *dir, *file; } tree[] = {
        {"/home/Asha/OS", "practical.txt"},
        {"/home/Ravi/DB", "record.txt"}
    };

    puts("Single-level directory:");
    for (int i = 0; i < 2; i++) printf("/%s\n", single[i]);

    puts("\nTwo-level directory:");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("/%s/%s\n", two[i].user, two[i].file[j]);

    puts("\nHierarchical directory:");
    for (int i = 0; i < 2; i++)
        printf("%s/%s\n", tree[i].dir, tree[i].file);
    return 0;
}
