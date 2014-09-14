#include"postfix.h"
void handle_cal()
{
    char operator;
    int a ,b;
    b=pop_num();
    a=pop_num();
    operator=pop_oper();
    switch(operator)
    {
        case '+':push_num(a+b);break;
        case '-':push_num(a-b);break;
        case '*':push_num(a*b);break;
        case '/':push_num(a/b);break;
    }
}
