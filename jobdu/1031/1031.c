#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF,n>0)
	{
		int count=0;
		while(n>1)
		{
			if(n%2==0)
				n=n/2;
			else
				n+=(n+1)/2;
			count++;
		}
		printf("%d\n",count );
	}
	return 0;
}