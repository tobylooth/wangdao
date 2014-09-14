#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int N;
	int countdivisor(long  n);
	while(scanf("%d",&N)!=EOF,N!=0)
	{
		long arr[N];
		for(int i=0;i<N;i++)
			scanf("%ld",&arr[i]);
		for(int i=0;i<N;i++)
		countdivisor(arr[i]);
	}
	return 0;
}
int countdivisor(long  n)
{
	int count=0;
	long  rt;
	rt=sqrt(n);
	for(long  i=1;i<=rt;i++)
	{
		if(n%i==0)
			count+=2;
	}
	if(rt*rt==n)
	count--;
	printf("%d\n", count);		
}