// Write a program to create clac using thread

// #include <stdio.h>
// #include <pthread.h>
#include <bits/stdc++.h>

using namespace std;

struct op
{
    int op1, op2;
};

void *add(void *a1)
{
    struct op *opp = (struct op *)a1;
    cout << "Add-> " << (opp->op1 + opp->op2) << endl;
}

void *sub(void *a1)
{
    struct op *opp = (struct op *)a1;
    cout << "Sub-> " << (opp->op1 - opp->op2) << endl;
}

void *mul(void *a1)
{
    struct op *opp = (struct op *)a1;
    cout << "Mul-> " << (opp->op1) * (opp->op2) << endl;
}

void *div(void *a1)
{
    struct op *opp = (struct op *)a1;
    cout << "Div-> " << (opp->op1 / opp->op2) << endl;
}

int main()
{
    pthread_t Add;
    pthread_t Sub;
    pthread_t Mul;
    pthread_t Div;
    struct op a1;
    a1.op1 = 10;
    a1.op2 = 2;
    struct op *a2 = &a1;

    pthread_create(&Add, NULL, add, (void *)a2);
    pthread_create(&Sub, NULL, sub, (void *)a2);
    pthread_create(&Mul, NULL, mul, (void *)a2);
    pthread_create(&Div, NULL, div, (void *)a2);

    pthread_join(Add, NULL);
    // pthread_join(Sub, NULL);
    // pthread_join(Mul, NULL);
    // pthread_join(Div, NULL);

    cout << "Main\n";

    return 0;
}