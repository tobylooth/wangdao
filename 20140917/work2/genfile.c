#include "head.h"

using namespace std;
void genfile(const string &filename,int n)
{
    int fd,value;
    if((fd=open(filename.c_str(),O_CREAT | O_WRONLY | O_TRUNC,0666))==-1)
    {
        perror("open fail");
        exit(-1);
    }
    for(int i=0; i < n; ++i)
    {
        value=rand()%N;
        char text[100];
        snprintf(text,sizeof (text),"%d\n",value);
        if(write(fd,text,strlen(text))==-1)
        {
            perror("write");
            exit(-1);
        }
    }
    close(fd);
}
