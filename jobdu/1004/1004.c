#include<stdio.h>
#define X 100
int main()
{
	int a[X],b[X];
	int m,n;
	while(scanf("%d",&m)!=EOF)	
	{
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&b[i]);
		int mid,median;
		if ((m+n)%2)
			mid=(m+n+1)/2;
		else
			mid=(m+n)/2;
		for (int i=0,j=0;(i+j)<mid;)
		{	
			if (i<m&&j<n)
			{
				if(a[i]>b[j])
				{
					median=b[j];
					j++;
				}
				else
				{
					median=a[i];
					i++;
				}
				/* code */
			}
			if(i>=m)
			{
				median=b[mid-m-1];
				break;
			}	
			if(j>=n)
			{
				median=a[mid-n-1];
				break;
			}		
		}
		printf("%d\n",median);
	}
	return 0;
}