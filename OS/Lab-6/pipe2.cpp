// WAP to pass a message from parent process to child process.
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main()
{
    int fd[2];
    int p1 = pipe(fd);
    pid_t c = fork();

    if (c > 0)
    {
        write(fd[1], "Hello", 5);
    }
    if (c == 0)
    {
        char buff[100];
        int x = read(fd[0], buff, sizeof(buff));
        write(1, buff, x);
    }

    return 0;
}
