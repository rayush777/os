// WAP to pass a message from child process to parent process.

#include <unistd.h>
#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    int fd[2];
    int p1 = pipe(fd);

    pid_t c = fork();

    if (c > 0)
    {
        char buff[100];
        wait(NULL);
        int x = read(fd[0], buff, sizeof(buff));
        cout << "Parent" << endl;
        write(1, buff, x);
    }
    if (c == 0)
    {
        cout << "Child" << endl;
        write(fd[1], "Hello\n", 6);
    }

    return 0;
}
