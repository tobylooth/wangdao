#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

ssize_t read(int fd,char *buf,ssize_t count)
{
    ssize_t nleft=count,readn;
    char *bufpos=buf;
    while(nleft>0)
    {
        memset(bufpos,0,count);
        readn=read(fd,bufpos,nleft);
        if(readn<0)
        {
            perror("readn");
            exit(1);
        }
        nleft-=readn;
        bufpos+=readn;
    }
}




ssize_t write(int fd,char *buf,ssize_t count)
{
    ssize_t nleft=count,readn;
    char *bufpos=buf;
    while(nleft>0)
    {
        readn=write(fd,bufpos,nleft);
        if(readn<0)
        {
            perror("readn");
            exit(1);
        }
        nleft-=readn;
        bufpos+=readn;
    }
}
