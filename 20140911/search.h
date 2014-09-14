#ifndef _CONCURRENCT_SEARCH_
#define _CONCURRENCT_SEARCH_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>

#define PATH "/usr/include"

void searchstr(char *filename,char str[]);
void searchdir(char *dir,int depth,char s[]);

#endif
