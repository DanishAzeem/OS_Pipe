#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

void main()
{
    int pd[2],n;
    int buff[30];
    pid_t pid;
    pipe(pd);
    pid = fork();
    if(pid > 0)
    {
        close(pd[0]);
        write(pd[1], "hello this is child", 30);
        close(pd[1]);
        exit(0);

    }
    else{
        close(pd[1]);
        n =read(pd[0], buff, 30);
        write(1,buff,n);
        close(pd[0]);
    }
}