#include<stdio.h>
int main(int argc, char const *argv[])
{
	int N,M;
	while(scanf("%d",&N)!=EOF,N>0)
	{
		scanf("%d",&M);
		int matrx[N+1][N+1],a,b;
		for (int i = 0; i <= N; ++i)
			for(int j=0;j<=N;j++)
				matrx[i][j]=0;
		for(int i=0;i<M;i++)
		{
			scanf("%d%d",&a,&b);
			if(a==b)
				matrx[a][a]=0;
			else
			{
				matrx[a][b]=1;
				matrx[b][a]=1;
			}
		}
		int sign=0;
		for (int i = 1; i <= N; ++i)
		{	int temp=0;
			for(int j=1;j<=N;j++)
				temp+=matrx[i][j];
			if(!(temp>0&&temp%2==0))
				sign=1;
		}
		if(sign==0)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}