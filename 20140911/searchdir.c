#include"search.h"

void searchdir(char *dir,int depth,char s[])
{
    DIR *dir_search;
    if((dir_search=opendir(dir))==NULL)
    {
        perror("opendir");
        exit(-1);
    }
    struct dirent *item_dir;
    struct stat statbuf;
    chdir(dir);

    while((item_dir=readdir(dir_search))!=NULL)
    {
        lstat(item_dir->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode))
        {
            if(strcmp(".",item_dir->d_name)==0||strcmp("..",item_dir->d_name)==0)
                continue;
            searchdir(item_dir->d_name,depth+4,s);
        }
        else
        {
            searchstr(item_dir->d_name,s);

        }
    }
    chdir("..");
    closedir(dir_search);

}

