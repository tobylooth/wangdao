#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF,n>0)
	{
		int num[n],temp;
		for (int i = 0; i < n; ++i)
			scanf("%d",&num[i]);
		for (int i = 0; i < n; ++i)
		{
			temp=num[i];
			while(temp>1)
			{
				if(temp%2==0)
					temp/=2;
				else
					temp=(temp*3+1)/2;
				for(int j=0;j<n;j++)
					if(temp==num[j])
						num[j]=-1;
			}
		}
		int loca;
		for (int i = 0; i < n; ++i)
			if(num[i]!=-1)
			{
				loca=i;
				break;
			}
		for (int i = n-1; i >loca; --i)
		{
			if(num[i]!=-1)
				printf("%d ",num[i] );	
		}
		printf("%d\n",num[loca] );

	}
	return 0;
}