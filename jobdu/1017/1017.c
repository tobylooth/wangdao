#include<stdio.h>
#include<limits.h>
int main(int argc, char const *argv[])
{
	int N;
	while(scanf("%d",&N)!=EOF,N>0){
		int n=N*(N-1)/2;
		int tr[N+1][N+1];
		for (int i = 1; i <= N; ++i)
			for(int j=1;j<=N;j++)
				tr[i][j]=0;
		int a,b,c;
		for (int i = 0; i < n; ++i){
			scanf("%d%d%d",&a,&b,&c);
			tr[b][a]=tr[a][b]=c;
		}
		int dist[N+1],distance=0;
		for (int i = 1; i <= N; ++i)
			dist[i]=tr[1][i];
		for (int i = 1; i < N; ++i)
		{
			dist[0]=INT_MAX;
			int temp;
			for(int j=1;j<=N;j++)
				if((dist[j]<dist[0])&&(dist[j]>0))
				{
					dist[0]=dist[j];
					temp=j;
				}
			distance+=dist[0];
			for (int j = 1; j <= N; ++j)
				if(tr[temp][j]<dist[j])
					dist[j]=tr[temp][j];	
		}
		printf("%d\n",distance );
			
	}
	return 0;
}