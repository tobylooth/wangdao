#include"postfix.h"
int stoi_my(char s[])
{
    int val=0,flag=0;
    char *p;
    p=s;
    if(*p=='-')
    {
        flag=1;
        p++;
    }
    int i;
    while(*p!='\0')
    {
        val=val*10+(*p-'0');
        p++;
    }
    if(flag==0)
        return val;
    else
        return -val;

}

