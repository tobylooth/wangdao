#include"postfix.h"
void main(int argc,char *argv[])
{
    char s[]="-(((11*(33-22)+44)/2-((15-13)*(30-12)+33)/3)*2-5) ";
   // char s[]="3+-4";
    int result;
    postfix_cal(s,&result);
    printf("result=%d\n",result);
}
