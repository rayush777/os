#include <stdio.h>
#include <unistd.h>

int main()
{
    char currDir[100];
    getcwd(currDir, sizeof(currDir));
    printf("%s\n", currDir);
}