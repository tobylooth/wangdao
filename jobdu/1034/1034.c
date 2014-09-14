#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n,m;
	int sort(int a[],int x);
	while(scanf("%d%d",&n,&m)!=EOF,n!=0&&m!=0)
	{
		int p[n];
		for (int i = 0; i < n; ++i)
			scanf("%d",&p[i]);
		sort(p,n);
		if(m>n)
		{
			for (int i = 0; i < n-1; ++i)
				printf("%d ",p[i] );
			printf("%d\n",p[n-1] );
		}
		else
		{
			for(int i=0;i<m-1;i++)
				printf("%d ",p[i] );
			printf("%d\n",p[m-1] );

		}

	}
	return 0;
}
int sort(int a[],int x)
{
	int value=a[0],i=0,j=x-1;
	if(j>0)
	{
		while(i<j)
		{
			for(;j>i;j--)
				if(a[j]>value)
				{
					a[i]=a[j];
					break;
				}
			for(;i<j;i++)
				if(a[i]<value)
				{
					a[j]=a[i];
					break;
				}
		}
		a[i]=value;
		sort(a,i);
		sort(a+i+1,x-i-1);
	}
	return 0;
}