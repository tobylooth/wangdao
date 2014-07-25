#include<stdio.h>
long long  L1,L2,L3,C1,C2,C3,N;
int main()
{
	freopen("test.txt","r",stdin);
	while(scanf("%lld",&L1)!=EOF)
	{
		long long   A,B;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&L2,&L3,&C1,&C2,&C3,&A,&B,&N);
		long long  a[N+1],b[N+1][N+1];
		a[0]=a[1]=0;
		int mincost(long long  a[],long long q, long long  m,long long (*b)[N+1]);
		for(int i=2;i<=N;i++)
			scanf("%lld",&a[i]);
		for(int i=0;i<=N;i++)
		{
			b[i][i]=0;
			b[i][0]=0;
			b[0][i]=0;
			long long temp=a[i+1]-a[i];
			if(temp>L2)
				b[i][i+1]=C3;
			else
				if(temp>L1)
					b[i][i+1]=C2;
				else
					b[i][i+1]=C1;
		}
			
		for(int i=2;i<N;i++)
		{
			for(int j=1;i+j<=N;j++)
			{
				long long  tempmin=b[j][j+1]+b[j+1][j+i];
				for(int k=2;k<i;k++)
					if((b[j][j+k]+b[j+k][j+i])<tempmin)
						tempmin=b[j][j+k]+b[j+k][j+i];
				long long temp=a[j+i]-a[j];
				if(temp<=L3)
				{
					if(temp>L2)
						{
							if(tempmin>C3)
								tempmin=C3;
						}
					else
						if(temp>L1)
						{
							if(tempmin>C2)
								tempmin=C2;
						}
						else
							if(tempmin>C1)
								tempmin=C1;
				}
				b[j][j+i]=tempmin;
			}
		}
		for(int i=0;i<=N;i++)
			for(int j=0;j<=N;j++)
				b[j][i]=b[i][j];
		printf("%lld\n",b[A][B] );
	}
	return 0;
}
