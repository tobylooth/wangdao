#include<stdio.h>
#include<limits.h>
#define N 100
int main(int argc, char const *argv[])
{
	int m,A,B;
	while(scanf("%d",&m)!=EOF,m>0)
	{
		scanf("%d%d",&A,&B);
		int a[N],b[N];
		for (int i = 0; i < N; ++i)
		{
			a[i]=0;
			b[i]=0;
		}
		int ca=0,cb=0,sign=0,count=0;
		while(1)
		{
			a[ca]=A%m;
			A=A/m;
			ca++;
			if(A==0)
				break;
		}
		while(1)
		{
			b[cb]=B%m;
			B/=m;
			cb++;
			if(B==0)
				break;
		}
		count=ca>cb?ca:cb;
		for (int i = 0; i < count; ++i)
		{
			a[i]+=b[i]+sign;
			sign=a[i]/m;
			a[i]%=m;
		}
		if(sign>0)
		{
			a[count]=sign;
			count++;
		}
		for (int i = count-1; i >=0;i--)
			printf("%d",a[i] );
		printf("\n");
	}
	return 0;
}