#ifndef _POSTFIX_CAL_
#define _POSTFIX_CAL_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/socket.h>

typedef struct tag_operation
{
    char oper[200];
    int  top;
}OPER,*pOPER;
typedef struct tag_number
{
    int arr[200];
    int top;
}NUM_OP,*pNUM_OP;

OPER oper;
NUM_OP num_op;

int stoi_my(char s[]);
char pop_oper();
void push_oper(char c);
int pop_num();
void push_num(int a);
int priority_my(char opt,char opt_top);
void blank_del(char s[]);
void handle_cal();
void postfix_cal(char exp[],int *res);
#endif
