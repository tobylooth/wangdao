#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define PATH "read.txt"
#define WRITE "write.txt"
#define N 10
void readn(int fd)
{
    int cntn=0,nleft,counts=0,countloop=0;
    char buff[N];
    while(memset(buff,0,sizeof(buff)),(cntn=read(fd,buff,N)>0))
    {
        counts++;
        if(cntn==N)
        continue;
        else
        {
            while(cntn<N)
            {
                int ctemp=0;
                countloop++;
                memset(buff,0,sizeof(buff));
                ctemp=read(fd,buff,N-cntn);
                if(ctemp>0)
                    cntn+=ctemp;
                else if(ctemp==0)
                    break;
                else
                {
                    perror("sdafs");
                    break;
                }
            }
        }
    }
    if(cntn==0)
        printf("read over\n");
    if(cntn<0)
        perror("read error");
}
void main(int argc,char argv[])
{
    FILE *fd;
    fd=fopen(PATH,"r");
    if(fd==NULL)
    {
        perror("open fail");
        exit(-1);
    }
    int ffd;
    ffd=fileno(fd);
    readn(ffd);
    fclose(fd);
}

