#include<stdio.h>
#include<string.h>
#define N 1030
int c[N];
int main(int argc, char const *argv[])
{
	
	int creattree(char  s[],int a[],int t);
	int n;
	while(scanf("%d",&n)!=EOF,n!=0)
	{
		for(int i=0;i<N;i++)
		c[i]=-1;
		char s[11];
		int len;
		scanf("%s",s);
		len=strlen(s);
		creattree(s,c,len);
		for(int i=0;i<n;i++)
		{
			int b[N];
			for (int j = 0; j < N; ++j)
			b[j]=-1;
			char s1[11];
			scanf("%s",s1);
			len=strlen(s1);
			creattree(s1,b,len);
			for(int j=0;j<N;j++)
			{
				if(c[j]!=b[j])
				{

					printf("NO\n");
					break;
				}
				if(j==N-1)
					printf("YES\n");
				
			}

		}

	}
	return 0;
}
int creattree(char s[],int a[],int t)
{
	for (int i = 0; i < t; ++i)
	{
		int temp;
		temp=s[i]-'0';
		for(int j=1;j<N;)
		{
			if(a[j]==-1)
			{
				a[j]=temp;
				break;
			}
			else if(a[j]>temp)
				j=2*j;
			else 
				j=2*j+1;
		}
		/* code */
	}
	return 0;

}