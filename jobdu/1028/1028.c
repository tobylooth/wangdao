#include<stdio.h>
#include<limits.h>
int main(int argc, char const *argv[])
{
	int N;
	while(scanf("%d",&N)!=EOF,N>0)
	{
		int a,b,c,d;
		int town[N+1][N+1];
		for (int i = 0; i <= N; ++i)
			town[i][i]=-1;
		for (int i = 0; i < (N*(N-1)/2); ++i)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(d==0)
				town[a][b]=c;
			else
				town[a][b]=0;
			town[b][a]=town[a][b];
		}
		int cost[N+1],result=0;
		for (int i = 0; i <= N; ++i)
			cost[i]=town[1][i];
		for (int i = 1; i <N; ++i)
		{
			int min=INT_MAX,minid;
			for(int j=1;j<=N;j++)
			{
				if(cost[j]>-1&&cost[j]<min)
				{
					min=cost[j];
					minid=j;
				}
			}
			result+=min;
			for(int j=1;j<=N;j++)
				if(town[minid][j]<cost[j])
					cost[j]=town[minid][j];
		}
		printf("%d\n",result );
			
	}
	return 0;
}