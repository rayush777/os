// 3. Write a program to create a child process that should run pwd command and the parent process should run ls command.

#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main()
{
    pid_t c = fork();
    if (c == 0)
    {
        cout << "Child Process" << endl;
        execl("/bin/pwd", "-L", NULL);
    }
    if (c > 0)
    {
        cout << "Parent Process" << endl;
        execl("/bin/ls", "-l", NULL);
        // wait(NULL);
    }
}