// Write a program to execute ls command using execl.

#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main()
{
    cout << "Current Process" << endl;
    execl("/bin/ls", "-l", NULL);
    cout << "Back to Current Porcess" << endl;
    return 0;
}