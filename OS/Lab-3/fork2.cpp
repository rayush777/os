#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    pid_t q = fork();
    if (q > 0){

        cout << "Hello form Parent" << endl;
    }
    if (q == 0)
        cout << "Hello from Child" << endl;
    if (q < 0)
        cout << "Hello" << endl;

    return 0;
}
