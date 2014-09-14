#include<stdio.h>
#include<limits.h>
int main(int argc, char const *argv[])
{
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF,N!=0)
	{
		int town[M+1][M+1];
		int a,b,c;
		for (int i = 0; i <= M; ++i)
			for(int j=0;j<=M;j++)
				if(i!=j)
				town[i][j]=INT_MAX;
				else
					town[i][j]=0;
		for (int i = 0; i < N; ++i)
			{
				scanf("%d%d%d",&a,&b,&c);
				if(c<town[a][b])
					{
						town[a][b]=c;
						town[b][a]=town[a][b];
					}
			}
		int dist[M+1];
		for (int i = 0; i <=M; ++i)
			dist[i]=town[1][i];
		int min,minid,sign=0,result=0;
		for (int i = 1; i < M; ++i)
		{
			min=INT_MAX;
			for(int j=1;j<=M;j++)
			{
				if((dist[j]>0)&&(dist[j]<min))
				{
					min=dist[j];
					minid=j;
				}	
			}
			if(min==INT_MAX)
				{
					sign=1;
					break;
				}
			result+=min;
			for (int j=1;j<=M ;j++)
				if(dist[j]>town[minid][j])
					dist[j]=town[minid][j];
		}
		if(sign==0)
			printf("%d\n",result );
		else
			printf("?\n");

	}
	return 0;
}