#include <bits/stdc++.h>

using namespace std;

int count = 0;

void *f1(void *a1)
{
    cout << "Entered thread ";
    ::count++;
    cout << "Thread Count2: " << ::count << "\n";
}

int main()
{
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;

    pthread_create(&t1, NULL, f1, NULL);
    pthread_create(&t2, NULL, f1, NULL);
    pthread_create(&t3, NULL, f1, NULL);
    pthread_create(&t4, NULL, f1, NULL);
}