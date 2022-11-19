// WAP to pass file name from parent process to child process and the child process should display file contents.

#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main()
{
    int fd[2];
    int p = pipe(fd);
    pid_t c = fork();

    if (c > 0)
    {
        write(fd[1], "f1.txt", );
    }
    if (c == 0)
    {
        char *file_name;
        int n = read(fd[0], file_name, sizeof(file_name));
        write(1, file_name, n);
    }

    // if (p1 > 0)
    // {
    //     write(fd[1], "Hello.txt", 9);
    //     // wait(NULL);
    //     char buff[100];
    //     int rd = read(fd1[0], buff, sizeof(buff));
    //     write(1, buff, rd);
    // }

    // if (p1 == 0)
    // {
    //     char buff[100];
    //     int x = read(fd[0], buff, sizeof(buff));
    //     int file = open(buff, O_RDONLY);
    //     char readfile[100];
    //     int rd = read(file, readfile, sizeof(readfile));
    //     // write(1, readfile, rd);
    //     write(fd1[1], readfile, rd);
    // }
    return 0;
}