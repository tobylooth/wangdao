#include "head.h"

using namespace std;
void findforce(FILE *fdw,FILE *fdf)
{
    char white[100],bigT[100];
    while(fscanf(fdf,"%s",bigT)==1)
    {
        int flag=0;
        rewind(fdw);
        while(fscanf(fdw,"%s",white)==1)
        {
            if(strcmp(bigT,white)==0)
            {
                flag=1;
                break;
            }
        }
 //       if(flag==0)
   //         cout<<bigT<<endl;
    }

}
