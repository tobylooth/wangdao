#include<stdio.h>
int main(int argc, char const *argv[])
{
	int a,b,k;
	while(scanf("%d%d%d",&a,&b,&k)!=EOF,!(a==0&&b==0))
	{
		int temp=1;
		for(int i=0;i<k;i++)
			temp=temp*10;
		if(a%temp==b%temp)
			printf("-1\n");
		else
			printf("%d\n",a+b );
	}
	return 0;
}