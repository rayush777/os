#include <unistd.h>
#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;
int main()
{
    pid_t c1 = fork();

    // pid_t c2 = fork();
    // pid_t c3 = fork();
    // pid_t c4 = fork();

    if (c1 > 0)
    {

        cout << "C1 Parent id: " << getpid() << endl;
        cout << "C1        id: " << c1 << endl;

        pid_t C2 = fork();

        if (C2 > 0)
        {
            cout << "C2 Parent id: " << getpid() << endl;
            cout << "C2        id: " << C2 << endl;

            pid_t C3 = fork();

            if (C3 > 0)
            {
                cout << "C3 Parent id: " << getpid() << endl;
                cout << "C3        id: " << C3 << endl;

                pid_t C4 = fork();

                if (C4 > 0)
                {
                    cout << "C4 Parent id: " << getpid() << endl;
                    cout << "C4        id: " << C4 << endl;
                }
                if (C4 == 0)
                {
                    sleep(3);
                    cout << "C4        id: " << getpid() << endl;
                    cout << "C4 Parent id: " << getppid() << endl;
                }
            }
            if (C3 == 0)
            {
                sleep(3);
                cout << "C3        id: " << getpid() << endl;
                cout << "C3 Parent id: " << getppid() << endl;
            }
        }
        if (C2 == 0)
        {
            sleep(3);
            cout << "C2        id: " << getpid() << endl;
            cout << "C2 Parent id: " << getppid() << endl;
        }
    }

    if (c1 == 0)
    {
        sleep(3);
        cout << "C1        id: " << getpid() << endl;
        cout << "C1 Parent id: " << getppid() << endl;
    }

    return 0;
}
