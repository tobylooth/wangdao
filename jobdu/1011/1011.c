#include<stdio.h>
int main(int argc, char const *argv[])
{
	int k;
	while(scanf("%d",&k)!=EOF,k>0)
	{
		int arr[k];
		for(int i=0;i<k;i++)
			scanf("%d",&arr[i]);
		int sum=-1,first=0;
		int last=k-1;
		for (int i = 0; i < k; ++i)
		{
			int temp=0;
			for(int j=i;j<k;j++)
			{
				temp=temp+arr[j];
				if(temp>sum)
				{
					sum=temp;
					first=i;
					last=j;
				}
			}
		}
		if(sum==-1)
			printf("%d %d %d\n",0,arr[first],arr[last]);
		else
			printf("%d %d %d\n",sum,arr[first],arr[last]);
	}
	return 0;
}