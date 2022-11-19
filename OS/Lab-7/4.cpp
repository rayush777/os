// // 4. Write a program to implement ls | sort functionality.

// #include <bits/stdc++.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <sys/wait.h>

// using namespace std;

// int main()
// {
//     pid_t c = fork();
//     if (c == 0)
//     {
//         int fd = open("test.txt", O_RDWR);
//         int stdfd = dup2(fd, 1);
//         execl("/bin/ls", "-l", NULL);
//     }
//     if (c > 0)
//     {
//         wait(NULL);
//     }
// }

/*
4. Write a program to implement ls | sort functionality.
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
    pid_t q = fork();

    if (p != -1)
    {
        if (q > 0)
        {
            wait(NULL);
            char buff[100];
            int rd = read(fd[0], buff, sizeof(buff));
            execl("/bin/sort", "", NULL);
        }
        if (q == 0)
        {
            // int fd_file = open("test.txt", O_RDWR);
            int newfd = dup(fd[1]);
            execl("/bin/ls", "-l", NULL);
        }
    }

    return 0;
}