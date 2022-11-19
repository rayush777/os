#include <bits/stdc++.h>

using namespace std;

void *f1(void *t1)
{
    cout << "Thread\n";
}

int main()
{
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, f1, NULL);
    pthread_create(&t2, NULL, f1, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    cout << "Main\n";

    return 0;
}