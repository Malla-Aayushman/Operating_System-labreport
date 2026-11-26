#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5

int buf[N], in = 0, out = 0;
sem_t empty, full, mutex;

void *produce(void *arg) {
    (void)arg;
    for (int x = 1; x <= N; x++) {
        sem_wait(&empty);
        sem_wait(&mutex);
        buf[in] = x;
        in = (in + 1) % N;
        printf("Produced %d\n", x);
        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void *consume(void *arg) {
    (void)arg;
    for (int i = 0; i < N; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        int x = buf[out];
        out = (out + 1) % N;
        printf("Consumed %d\n", x);
        sem_post(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main(void) {
    pthread_t p, c;

    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_create(&p, NULL, produce, NULL);
    pthread_create(&c, NULL, consume, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}
