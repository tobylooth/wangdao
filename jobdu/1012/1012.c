#include<stdio.h>
#define N 1024
int father[N];
int find(int x)
{
	if(father[x]!=x)
		father[x]=find(father[x]);
	return father[x];
}
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF,n>0)
	{
		int m,temp=0;
		scanf("%d",&m);
		for (int i = 0; i <=n; ++i)
			father[i]=i;
		int a,b;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			a=find(a);
			b=find(b);
			father[a]=b;
		}
		for(int i=0;i<=n;i++)
			if(father[i]!=i)
				temp++;
		printf("%d\n",n-1-temp );
	}
	return 0;
}