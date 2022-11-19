// Reader's writer's Problem (Reader priority)

#include <bits/stdc++.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

sem_t x, wsem;
int readerCount;

void *Writter(void *t)
{
    // while (true)
    // for (int i = 0; i < 20; i++)
    // {
    sem_wait(&wsem);
    cout << "Writter writting"
         << "\n";
    sem_post(&wsem);
    // }
}

void *Reader(void *t)
{
    // while (true)
    // for (int i = 0; i < 20; i++)
    // {
    sem_wait(&x);
    readerCount++;
    if (readerCount == 1)
        sem_wait(&wsem);
    sem_post(&x);
    cout << "Reading ... \tReadingCount: " << readerCount << "\n";
    sem_wait(&x);
    readerCount--;
    if (readerCount == 0)
        sem_post(&wsem);
    sem_post(&x);
    // }
}

int main()
{
    sem_init(&x, 0, 1);
    sem_init(&wsem, 0, 1);

    pthread_t r1, w1, r2, r3, r4, r5;

    pthread_create(&r1, NULL, Reader, NULL);
    pthread_create(&r2, NULL, Reader, NULL);
    pthread_create(&r3, NULL, Reader, NULL);
    pthread_create(&r4, NULL, Reader, NULL);
    pthread_create(&r5, NULL, Reader, NULL);
    pthread_create(&w1, NULL, Writter, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(r3, NULL);
    pthread_join(r4, NULL);
    pthread_join(r5, NULL);

    pthread_join(w1, NULL);

    return 0;
}

///studey about readers and writters problem

// 1. RW where reader having priority
// 2. RW where writter having priority
