#include"search.h"

void searchstr(char *filename,char str[])
{
    FILE *fd;
    if((fd=fopen(filename,"r"))==NULL)
    {
        perror("openfile");
        exit(-1);
    }
    char sbuf[1024];
    while(memset(sbuf,0,sizeof(sbuf)),fgets(sbuf,sizeof(sbuf),fd)!=NULL)
    {
        if(strstr(sbuf,str)!=NULL)
        {
        printf("%s\n",filename);
        break;
        }
    }
    fclose(fd);
    return;
}
