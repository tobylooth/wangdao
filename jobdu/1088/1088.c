#include<stdio.h>
int main(int argc, char const *argv[])
{
	int L,M;
	while(scanf("%d",&L)!=EOF)
	{
		scanf("%d",&M);
		int line[L+1],a,b;
		for(int i=0;i<=L;i++)
			line[i]=0;
		for(int i=0;i<M;i++)
		{
			scanf("%d%d",&a,&b);
			for(int j=a;j<=b;j++)
				line[j]=1;
		}
		int count=0;
		for(int i=0;i<=L;i++)
			if(line[i]==0)
				count++;
		printf("%d\n",count );
	}
	return 0;
}