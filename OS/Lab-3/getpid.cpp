#include <unistd.h>
#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;
int main()
{
    pid_t q = fork();
    if (q > 0)
    {
        wait(NULL); // it wait for child  process to terminate
        cout << "I am Parent id: " << getpid() << endl;
        cout << "I am Parent Child id: " << q << endl;
    }
    if (q == 0)
    {
        // cout << "exp: " << getppid() << endl;
        // cout << "exp: " << getppid() << endl;

        cout << "I am Child, my id: " << getpid() << endl;
        cout << "I am Child, my Parent id: " << getppid() << endl;
    }

    return 0;
}
