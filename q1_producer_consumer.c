#include <stdio.h>

int empty = 10, full = 0, item = 0;

int main(void) {
    int choice;

    do {
        printf("\n1 Produce  2 Consume  3 Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1 && empty) {
            printf("Produced item %d\n", ++item);
            empty--;
            full++;
        } else if (choice == 2 && full) {
            printf("Consumed item %d\n", item--);
            full--;
            empty++;
        } else if (choice == 1) {
            printf("Buffer full\n");
        } else if (choice == 2) {
            printf("Buffer empty\n");
        }
    } while (choice != 3);

    return 0;
}
