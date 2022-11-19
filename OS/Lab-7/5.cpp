/*
Write a program to achieve following:
    - Child process should open a file with the contents to be sorted, pass the contents to parent process.
    - Parent process should sort the contents of the file and display.
*/

#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    pid_t c = fork();
    if (c == 0)
    {
        int fd = open("test.txt", O_RDWR);
        int stdfd = dup2(fd, 1);
        execl("/bin/ls", "-l", NULL);
    }
    if (c > 0)
    {
        wait(NULL);
    }
}
