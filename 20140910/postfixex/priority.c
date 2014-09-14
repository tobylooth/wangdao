#include"postfix.h"
int  priority_my(char opt,char opt_top)
{
    int pri_table[6][6]=\
    {
        0,0,0,0,1,1,
        0,0,0,0,1,1,
        1,1,0,0,1,1,
        1,1,0,0,1,1,
        1,1,1,1,1,1,
        0,0,0,0,0,1
    };
    int row,col;
    switch(opt)
    {
        case '+':row=0;break;
        case '-':row=1;break;
        case '*':row=2;break;
        case '/':row=3;break;
        case '(':row=4;break;
        case ')':row=5;break;
    }
    switch(opt_top)
    {
        case '+':col=0;break;
        case '-':col=1;break;
        case '*':col=2;break;
        case '/':col=3;break;
        case '(':col=4;break;
        case '#':col=5;break;
    }
    return pri_table[row][col];
}
