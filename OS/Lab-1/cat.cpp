//  Implementation of cat command with echo and file concatenation functionalities.

#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv)
{
    //  if file name is not provided, then cat command work as echo
    if (argc == 1)
    {
        while (1)
        {
            char content[1000];
            int n = read(0, content, sizeof(content));
            write(1, content, sizeof(content));
        }
    }
    else
    {
        char *fileName = argv[1];
        int fd = open(fileName, O_RDONLY);
        char content[1000];
        int n = read(fd, content, sizeof(content));
        write(1, content, 1);
    }
    return 0;
}
