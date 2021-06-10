#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd_in, fd_out;
    int read_size;
    char buff[1024];

    fd_in = open(argv[1], O_RDONLY);
    fd_out = open(argv[2], O_WRONLY | O_CREAT, 00600);

    if(fd_in == -1)
    {
        printf("Open input file failed\n");
        return 0;
    }
    if(fd_out == -1)
    {
        printf("Open output file failed\n");
        return 0;
    }

    while(1)
    {
        read_size = read(fd_in, buff, 1024);
        if(read_size <= 0) break;//檢查輸入大小，<= 0時即為讀完或出錯
        write(fd_out, buff, read_size);
    }

    close(fd_in);
    close(fd_out);
    return 0;
}