#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	int reverse(int n);
	while(scanf("%d",&n)!=EOF)
	{
		int a,b;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			int sum1,sum2;
			sum1=reverse(a)+reverse(b);
			sum2=reverse(a+b);
			if(sum1==sum2)
				printf("%d\n",a+b );
			else
				printf("NO\n");
		}
	}
	return 0;
}
int reverse(int n)
{
	int m=0,temp=n;
	for(;temp/10!=0;)
	{
		m=(temp%10+m)*10;
		temp/=10;
	}
	m+=temp;
	return m;
}