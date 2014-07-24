#include<stdio.h>
#include<stdlib.h>
int main()
{
int M,N,count,*pa,*pb,*pc;
while(scanf("%d ",&M) != EOF)
{
if(M!=0)
{
count=0;
scanf("%d ",&N);
pa=(int *)malloc(M*N*sizeof(int));
pb=(int *)malloc(M*N*sizeof(int));
pc=(int *)malloc(M*N*sizeof(int));
int *pa_p,*pb_p,*pc_p;
pa_p=pa;
pb_p=pb;
for(int ia=0;ia<M;ia++)
for(int ja=0;ja<N;ja++,pa_p++)
 scanf("%d ",pa_p);
for(int ib=0;ib<M;ib++)
for(int jb=0;jb<N;jb++,pb_p++)
scanf("%d ",pb_p);
pa_p=pa;
pb_p=pb;
pc_p=pc;
for(int ic=0;ic<M;ic++)
{
int row=0;
for(int jc=0;jc<N;jc++,pa_p++,pb_p++,pc_p++)
{
*pc_p=*pa_p+*pb_p;
printf("%d--",*pc_p);
if(*pc_p!=0)
row++;
}
if(row==0)
count++;
}
pc_p=pc;
for(int i=0;i<N;i++)
{
int clo=0;
for(int j=0;j<M;j++)
{
if(*(pc_p+j*M+i)!=0)
clo++;
}
if(clo==0)
count++;
}
printf("%d  \n \n \n ",count);
for(int ia=0;ia<M;ia++)
{
for(int ja=0;ja<N;ja++,pa++)
printf("%d ",*pa);
printf("\n");
}
for(int ia=0;ia<M;ia++)
{
for(int ja=0;ja<N;ja++,pb++)
printf("%d ",*pb);
printf("\n");
}
for(int ia=0;ia<M;ia++)
{
for(int ja=0;ja<N;ja++,pc++)
printf("%d ",*pc);
printf("\n");
}
//free(pa);
//free(pb);
}
}
}
