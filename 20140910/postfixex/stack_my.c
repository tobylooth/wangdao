#include"postfix.h"
char pop_oper()
{
    if(oper.top>0)
    {
        oper.top--;
      return oper.oper[oper.top];
    }
    else
    {
        perror("pop_oper");
        exit(-1);
    }
}
void push_oper(char c)
{
    if(oper.top<sizeof(oper.oper))
    {
        oper.oper[oper.top]=c;
        oper.top++;
    }
}
void push_num(int a)
{
    if(num_op.top<sizeof(num_op.arr))
    {
        num_op.arr[num_op.top]=a;
        num_op.top++;
    }
}
int pop_num()
{
    if(num_op.top>0)
    {
        num_op.top--;
        return num_op.arr[num_op.top];
    }
    else
    {
        perror("pop_num");
        exit(-1);
    }
}
