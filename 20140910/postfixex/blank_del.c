#include"postfix.h"
void blank_del(char s[])
{
    int cnt=0;
    char *p;
    p=s;
    while(*p!='\0')
    {
        if(*p==' ')
        {
            p++;
        }
        else
        {
            s[cnt++]=*p++;
        }
    }
    s[cnt]='\0';

}
