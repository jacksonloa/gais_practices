#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd;
    int file_size;
    int i;

    fd = open(argv[1], O_RDWR);

    struct stat st;
    stat(argv[1], &st);
    file_size = st.st_size;

    for(i = 0; i < file_size/2; i ++)
    {
        char front[2] = {0}, back[2] = {0};
        lseek(fd, i, SEEK_SET);
        read(fd, front, 1);

        lseek(fd, -1*i-1, SEEK_END);
        read(fd, back, 1);

        lseek(fd, i, SEEK_SET);
        write(fd, back, 1);

        lseek(fd, -1*i-1, SEEK_END);
        write(fd, front, 1);
    }
    close(fd);
    return 0;
}
