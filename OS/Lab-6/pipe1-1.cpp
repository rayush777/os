// WAP to pass a message from parent process to child process.

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main()
{
    int fd[2], fd2[2];
    int p1 = pipe(fd);
    // cout << a << endl;
    cout << "File Dis: " << fd[0] << " " << fd[1] << endl;
    int p2 = pipe(fd2);
    cout << "File Dis: " << fd2[0] << " " << fd2[1] << endl;

    return 0;
}



