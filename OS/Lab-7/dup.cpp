/*
. Create a blank file: “Test.txt”.
    Write a program to achieve following:
    - Print “Hello” message on stdout.
    - Use dup2 in such a way that file behaves as stdout.
    - Print “Hello” again to ensure that this time the message goes to file, not to the stdout.

*/

#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main()
{
    int fd = open("test.txt", O_RDWR);
    // int fd1 = dup(fd);
    // int fd2 = dup2(fd, 7);

    // cout << fd << " " << fd1 << endl;
    // cout << fd2 << endl;

    // char buff[100];
    // int n = read(fd2, buff, sizeof(buff));
    // cout << buff << endl;

    //  Use dup2 in such a way that file behaves as stdout. -----------------

    int stdfd = dup2(fd, 1);
    cout << "std output";
    // int n = read(fd, buff1, sizeof(buff1));
    // write(1, (char *)"hello", 5);




    return 0;
}