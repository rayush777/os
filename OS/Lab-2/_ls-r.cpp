#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argvc, char *argc[])
{
    struct dirent *d;
    DIR *de;
    de = opendir(".");

    // if (!de)
    // {
    while ((d = readdir(de)) != NULL)
    {
        // if(d->d_name[0]=='.')
        // continue;
        cout << d->d_name << endl;
    }
    // }

    return 0;
}