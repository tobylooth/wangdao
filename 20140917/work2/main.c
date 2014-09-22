#include "head.h"
using namespace std;
int main()
{
    srand(832942);


    string namew="bigW.txt";
    string namet="bigT.txt";
    genfile(namew,SIZE1);
    genfile(namet,SIZE2);

    findbi(namew,namet);

//    FILE *fdw,*fdf;
//    fdw=fopen("bigW.txt","r");
//    if(fdw==NULL)
//    {
//        perror("openfile");
//        exit(EXIT_FAILURE);
//    }
//    fdf=fopen("bigT.txt","r");
//    if(fdf==NULL)
//    {
//        perror("openfdf");
//        exit(EXIT_FAILURE);
//    }
//
//
//    findforce(fdw,fdf);
//
//
//    fclose(fdw);
//    fclose(fdf);
    return 0;
}
