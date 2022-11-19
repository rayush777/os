#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char buff[100];
    int fd = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_WRONLY);
    int n = read(fd, buff, sizeof(buff));

    // write(1, buff, n);

    write(fd2, buff, n);

    return 0;
}