#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BLOCK "▒▒"
#define UP " ↑"
#define DOWN " ↓"
#define LEFT " ←"
#define RIGHT " →"
#define TRAV 'T'
typedef struct tag_maze
{
    int row;
    int col;
    struct tag_maze *next;
}MAZE,*pMAZE;
void add_stru(pMAZE *phead,char arr[][13][10],int row,int col,char *dire) ;
void back_stru(pMAZE *phead,char arr[][13][10],int *row,int *col);
