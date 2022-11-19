// Pass multiple arg to thread with struct

#include <stdio.h>
#include <pthread.h>

// using namespace std;

struct arg
{
    int x;
    char *y;
};

void *f1(void *a1)
{
    struct arg *a2 = (struct arg *)a1;
    printf("%s %d ", a2->y, a2->x);
}

int main()
{
    pthread_t t1;

    struct arg a1;
    a1.x = 7;
    a1.y = "Hi!";

    struct arg *a2 = &a1;

    pthread_create(&t1, NULL, f1, (void *)a2);
    pthread_join(t1, NULL);
    printf("Main\n");

    return 0;
}