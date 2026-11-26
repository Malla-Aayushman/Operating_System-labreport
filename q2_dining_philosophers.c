#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5

sem_t fork[N], room;

void *eat(void *arg) {
    int i = *(int *)arg;

    sem_wait(&room);
    sem_wait(&fork[i]);
    sem_wait(&fork[(i + 1) % N]);
    printf("Philosopher %d eats\n", i + 1);
    sem_post(&fork[(i + 1) % N]);
    sem_post(&fork[i]);
    sem_post(&room);
    return NULL;
}

int main(void) {
    pthread_t t[N];
    int id[N];

    sem_init(&room, 0, N - 1);
    for (int i = 0; i < N; i++) sem_init(&fork[i], 0, 1);
    for (int i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&t[i], NULL, eat, &id[i]);
    }
    for (int i = 0; i < N; i++) pthread_join(t[i], NULL);
    return 0;
}
