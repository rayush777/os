#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

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
        printf("%s\n", d->d_name);
    }
    // }

    return 0;
}