#include<stdio.h>
int main(int argc, char const *argv[])
{
	char a[6],b[81];
	while(scanf("%c",&a[0])!=EOF,a[0]!='#')
	{
		int n=1,m=0,c[6]={0};
		while(scanf("%c",&a[n])!=EOF,a[n]!='\n')
			n++;
		while(scanf("%c",&b[m])!=EOF,b[m]!='\n')
			m++;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i]==b[j])
					c[i]++;
		for (int i = 0; i < n; ++i)
			printf("%c %d\n",a[i],c[i] );
	}
	return 0;
}