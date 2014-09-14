#include"maze.h"
void back_stru(pMAZE *phead,char arr[][13][10],int *row,int *col)
{
    pMAZE delenode;
    delenode=*phead;
    if((*phead)==NULL)
    {
        printf("no way find\n");
        exit(0);
    }
    char buf[]="  ";
    strcpy(arr[delenode->row][delenode->col],buf);
    arr[delenode->row][delenode->col][9]=TRAV;
    *phead=(*phead)->next;
    free(delenode);
    delenode=NULL;
    if((*phead)==NULL)
    {
        printf("no way find\n");
        exit(0);
    }
    *row=(*phead)->row;
    *col=(*phead)->col;

}
