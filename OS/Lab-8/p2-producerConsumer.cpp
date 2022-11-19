#include <bits/stdc++.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

using namespace std;

sem_t m;
sem_t empty;
sem_t full;

const int n = 5;
int buff[n];

int in = 0, out = 0;

void *Producer(void *t)
{
    for (int i = 0; i < 50; i++)
    {
        sem_wait(&empty);
        sem_wait(&m);

        // CS Start
        buff[in] = 1;
        cout << "Iteam Produced : " << in << endl;
        in = (in + 1) % n;
        // CS Ends

        sem_post(&m);
        sem_post(&full);
    }
}

void *Consumer(void *t)
{
    for (int i = 0; i < 50; i++)
    {
        sem_wait(&full);
        sem_wait(&m);

        // CS Start
        buff[out] = 0;
        cout << "Iteam Consumed : " << out << endl;
        out = (out + 1) % n;
        // CS Ends

        sem_post(&m);
        sem_post(&empty);
    }
}

int main()
{
    // int n;
    // cin >> n;

    sem_init(&full, 0, 0);
    sem_init(&m, 0, 1);
    sem_init(&empty, 0, n);

    pthread_t pt;
    pthread_t ct;

    pthread_create(&pt, NULL, Producer, NULL);
    pthread_create(&ct, NULL, Consumer, NULL);

    pthread_join(pt, NULL);
    pthread_join(ct, NULL);
}
