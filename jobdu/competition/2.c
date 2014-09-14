#include<stdio.h>
int count=0;
void getcount(int push,int pop,int N)
{

	for (int i = 0; i < pop; ++i)
	{
		if (push<N)
			getcount(push+1,pop-i+1,N);
		else
		{
			count=(count++)%1000000007;
		}
		/* code */
	}
}
int main()
{
	int c;
	while(scanf("%d",&c)!=EOF)
	{
		int n;
		n=c/2;
		getcount(1,1,n);
		printf("%d\n",count);
		count=0;
	}
	/* code */
	return 0;
}