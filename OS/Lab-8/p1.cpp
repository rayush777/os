#include <bits/stdc++.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

using namespace std;

int counter = 0;
// pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

sem_t m;

void *f1(void *t)
{
    // pthread_mutex_lock(&m);
    sem_wait(&m);
    counter++;
    printf("\nThread entered at counter %d", counter);
    printf("\nThread exited at counter %d", counter);
    sem_post(&m);
    // pthread_mutex_unlock(&m);
}

/*
*/

int main()
{

    sem_init(&m, 0, 1);

    printf("Main function start\n");
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    pthread_t t5;

    pthread_create(&t1, NULL, f1, NULL);
    pthread_create(&t2, NULL, f1, NULL);
    pthread_create(&t3, NULL, f1, NULL);
    pthread_create(&t4, NULL, f1, NULL);
    pthread_create(&t5, NULL, f1, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);

    return 0;
}