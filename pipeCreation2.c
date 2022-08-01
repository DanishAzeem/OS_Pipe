#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
    int fd[2],n;
    int msg;
    char buff[50];
    
    pipe(fd);
    n = fork();

    if (n > 0)
    {
        close(fd[0]);
        write(fd[1], "please Write hello world\n", 50);
        close(fd[1]);
        exit(0);
    }
    else
    {
        close(fd[1]);
        msg = read(fd[0], buff, 50);
        write(1, buff, msg);
    }
}