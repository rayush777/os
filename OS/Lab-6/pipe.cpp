// write a program to create a pipe and

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main()
{
    int fd[2];
    int a = pipe(fd);
    // cout << a << endl;
    cout << "File Dis: " << fd[0] << " " << fd[1] << endl;
    return 0;
}