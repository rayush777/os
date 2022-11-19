#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

sem_t wmutex, rmutex;
int writercount = 0;

void *reader(void *t)
{
    sem_wait(&rmutex);

    printf("Reader is reading\n");
    printf("Writer count %d\n", writercount);

    sem_post(&rmutex);
}

void *writer(void *t)
{

    sem_wait(&wmutex);
    writercount++;
    if (writercount == 1)
    {
        sem_wait(&rmutex);
    }
    sem_post(&wmutex);

    printf("Writer %d is writing \n", writercount);

    sem_wait(&wmutex);
    writercount--;
    if (writercount == 0)
    {
        sem_post(&rmutex);
    }

    sem_post(&wmutex);
}

int main()
{

    sem_init(&wmutex, 0, 1);
    sem_init(&rmutex, 0, 1);

    pthread_t r, w1, w2, w3;

    pthread_create(&r, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_create(&w2, NULL, writer, NULL);
    pthread_create(&w3, NULL, writer, NULL);

    pthread_join(r, NULL);
    pthread_join(w1, NULL);
    pthread_join(w2, NULL);
    pthread_join(w3, NULL);

    return 0;
}
