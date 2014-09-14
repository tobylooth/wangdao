#include<stdio.h>
#include<limits.h>
#define N  INT_MAX
struct side
{
	int dist;
	int spend;
};
int main(int argc, char const *argv[])
{
	int m,n,start,end;
	while(scanf("%d%d",&n,&m)!=EOF,n!=0||m!=0)
	{
		struct side adjm[n+1][n+1];
		for (int i = 1; i <= n; ++i)
			for(int j=1;j<=n;j++)
				{
					adjm[i][j].dist=N;
					adjm[i][j].spend=N;
				}
		for (int i = 1; i <= m; ++i)
		{
			int a ,b ,c ,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(adjm[a][b].dist>c)
			{
				adjm[a][b].dist=c;
				adjm[a][b].spend=d;
				adjm[b][a]=adjm[a][b];
			}
			else
				if(adjm[a][b].dist==c)
					if(adjm[a][b].spend>d)
					{
						adjm[a][b].spend=d;
						adjm[b][a].spend=d;
					}
		}
		scanf("%d%d",&start,&end);
		struct side distance[n+1];
		for (int i = 1; i <= n; ++i)
			distance[i]=adjm[start][i];
		int  sign[n+1];
		for(int i=1;i<=n;i++)
			sign[i]=0;
		for (int i = 1; i < n; ++i)
		{
			int mindist=INT_MAX,mindistID,minspend;
			for(int j=1;j<=n;j++)
			{
				if(sign[j]==0&&distance[j].dist<mindist)
				{
					mindist=distance[j].dist;
					minspend=distance[j].spend;
					mindistID=j;
				}
			}
			sign[mindistID]=1;
			for(int j=1;j<=n;j++)
			{
				if(distance[j].dist>(mindist+adjm[mindistID][j].dist)&&adjm[mindistID][j].dist<INT_MAX)
				{
					distance[j].dist=mindist+adjm[mindistID][j].dist;
					distance[j].spend=minspend+adjm[mindistID][j].spend;
				}
					
				if(distance[j].dist==(mindist+adjm[mindistID][j].dist)&&adjm[mindistID][j].dist<INT_MAX)
				{
					if(distance[j].spend>(minspend+adjm[mindistID][j].spend))
						distance[j].spend=minspend+adjm[mindistID][j].spend;
				}
			}
		}
		printf("%d %d\n",distance[end].dist,distance[end].spend );
	}
	return 0;
}