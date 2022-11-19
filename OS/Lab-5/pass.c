// Pass a char string to thread function

#include <stdio.h>
#include <pthread.h>

// using namespace std;

void *f1(void *t1)
{
    char *s1 = (char *)t1;
    printf("%s ", (char *)t1);
    printf("Thread\n");
    // cout << s1 << endl;
    // cout << "Thread\n";
}

int main()
{
    pthread_t t1;
    // pthread_t t2;

    char *s1 = "Hello";
    char *s2 = "Hello 2";

    pthread_create(&t1, NULL, f1, (void *)s1);
    pthread_create(&t1, NULL, f1, (void *)s2);
    // pthread_create(&t2, NULL, f1, NULL);

    pthread_join(t1, NULL);
    // pthread_join(t2, NULL);
    printf("Main\n");

    return 0;
}