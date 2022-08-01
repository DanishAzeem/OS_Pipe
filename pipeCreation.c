#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
    int fd[2], n;  // file discreptor
    pid_t pc;
    char buff[30];
    pipe(fd);
    pc = fork();
    if(pc > 0)
    {
        close(fd[0]);
        write(fd[1], "hello my child\n", 30);
        close(fd[1]);
        exit(0);
        //wait();

    }
    else
    {
        close(fd[1]);
        n = read(fd[0], buff, 30);
        write(1, buff, n);
    }
}