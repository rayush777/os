/*
Write a program to achieve following:
    - Child process should open a file with the contents to be sorted, pass the contents to parent process.
    - Parent process should sort the contents of the file and display.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
    int fd[2];
    int p = pipe(fd);

    if (p == -1)
    {
        printf("Error while creating pipe");
    }
    else
    {
        pid_t q = fork();

        if (q > 0)
        {
            write(fd[1], "p5_test.txt", 11); //passig file name to child
            wait(NULL);
            close(fd[1]);
            dup2(fd[0], 0); //  reading file content form pipe
            execl("/bin/sort", "", NULL);
        }

        if (q == 0)
        {
            char fbuff[100];
            int frd = read(fd[0], fbuff, sizeof(fbuff)); // reading file nam from pipe
            close(fd[0]);
            int file_fd = open(fbuff, O_RDWR);
            char buff[100];
            int rd = read(file_fd, buff, sizeof(buff));
            dup2(fd[1], 1);
            write(1, buff, rd); // writing file content on pipe
        }
    }

    return 0;
}