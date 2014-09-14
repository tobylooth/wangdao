#include"maze.h"
void main(int argc,char argv[])
{
    srand(time(NULL));
    char arr[13][13][10]=\
    {
        "▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒",
        "▒▒","  ","  ","  ","▒▒","▒▒","▒▒","  ","▒▒","  ","  ","  ","▒▒",
        "▒▒","▒▒","▒▒","  ","▒▒","▒▒","  ","  ","▒▒","▒▒","▒▒","  ","▒▒",
        "▒▒","▒▒","▒▒","  ","▒▒","▒▒","  ","  ","▒▒","▒▒","▒▒","  ","▒▒",
        "▒▒","  ","  ","  ","  ","  ","  ","▒▒","▒▒","▒▒","  ","  ","▒▒",
        "▒▒","  ","▒▒","▒▒","▒▒","▒▒","  ","▒▒","▒▒","▒▒","  ","▒▒","▒▒",
        "▒▒","  ","  ","▒▒","▒▒","  ","  ","▒▒","▒▒","▒▒","  ","▒▒","▒▒",
        "▒▒","  ","  ","▒▒","▒▒","▒▒","  ","▒▒","▒▒","▒▒","  ","▒▒","▒▒",
        "▒▒","  ","  ","  ","▒▒","▒▒","  ","▒▒","▒▒","▒▒","  ","▒▒","▒▒",
        "▒▒","  ","  ","  ","  ","  ","  ","▒▒","▒▒","▒▒","  ","▒▒","▒▒",
        "▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","  ","▒▒","▒▒","▒▒","  ","  ","▒▒",
        "▒▒","▒▒","  ","  ","  ","  ","  ","  ","  ","  ","▒▒","  ","▒▒",
        "▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒","▒▒"
    };
    int row=1,col=1;
    for(row=0;row<13;row++)
    {
        for(col=0;col<13;col++)
        {
            printf("%s",arr[row][col]);
            arr[row][col][9]='0';
        }
        printf("\n");
    }
        row=1;col=1;
    pMAZE mazehead,mnew;
        mnew=(pMAZE)calloc(1,sizeof(MAZE));
        mnew->row=row;
        mnew->col=col;
        mnew->next=NULL;
        mazehead=mnew;
        strcpy(arr[row][col],"囧");
        arr[row][col][9]=TRAV;
    while(row<11||col<11)
    {
        printf("buggggggggggg%d ,%d,%d\n",row,col,sizeof(BLOCK));
        if(strcmp(arr[row][col+1],BLOCK)!=0&&arr[row][col+1][9]!=TRAV)
        {
            col++;
            add_stru(&mazehead,arr,row,col,RIGHT);
            continue;
        }
        if(strcmp(arr[row+1][col],BLOCK)!=0&&arr[row+1][col][9]!=TRAV)
        {
            row++;
            add_stru(&mazehead,arr,row,col,DOWN);
            continue;
        }
        if(strcmp(arr[row][col-1],BLOCK)!=0&&arr[row][col-1][9]!=TRAV)
        {
            col--;
            add_stru(&mazehead,arr,row,col,LEFT);
            continue;
        }
        if(strcmp(arr[row-1][col],BLOCK)!=0&&arr[row-1][col][9]!=TRAV)
        {
            row--;
            add_stru(&mazehead,arr,row,col,UP);
            continue;
        }
        back_stru(&mazehead,arr,&row,&col);
    }
    system("clear");
    for(row=0;row<13;row++)
    {
        for(col=0;col<13;col++)
            printf("%s",arr[row][col]);
        printf("\n");
    }
    printf("find a way\n");

}
