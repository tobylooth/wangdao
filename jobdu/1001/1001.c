#include<stdio.h>
#include<stdlib.h>
int main()
{
int M,N,count;
while(scanf("%d",&M))
{
if(M!=0)
{
count=0;
scanf("%d",&N);
int a[10][10];
for(int i=0;i<M;i++)
for(int j=0;j<N;j++)
scanf("%d",&a[i][j]);
for(int i=0;i<M;i++)
for(int j=0;j<N;j++)
{
int temp;
scanf("%d",&temp);
a[i][j] +=temp;
}
for(int i=0;i<M;i++)
{
for(int j=0;j<N;j++)
{
if(a[i][j]!=0)
break;
if(j==N-1)
count++;
}
}
for(int i=0;i<N;i++)
{
for(int j=0;j<M;j++)
{
if(a[i][j]!=0)
break;
if(j==M-1)
count++;
}
}
printf("%d\n",count);
}
else break;
}
return 0;
}
