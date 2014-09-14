#include"maze.h"
void add_stru(pMAZE *phead,char arr[][13][10],int row,int col,char *dire)
{
    pMAZE newnode;
    newnode=(pMAZE)calloc(1,sizeof(MAZE));
    newnode->row=row;
    newnode->col=col;
    strcpy(arr[row][col],dire);
    arr[row][col][9]=TRAV;
    newnode->next=*phead;
    *phead=newnode;
}
