#include<stdio.h>
#define N 10
int main(int argc, char const *argv[])
{
	double m,result=0;
	char c;
	double caculate(double a,char b);
	while(scanf("%lf",&m)!=EOF)
	{
		while(scanf("%c",&c)!=EOF,c==' ');
		if(m==0&&c=='\n')
			return 0;
		else
			result=caculate(m,c);
		printf("%0.2f\n",result );
	}
	return 0;
}
double caculate(double a,char b)
{
	double n[N],tmn,result=0;
	int i,sign;
	i=0;sign=0;
	char c[N],tmc;
	n[i]=a;
	c[i]=b;
	while(i>=0)
	{
		if(sign==0){
		scanf("%lf",&n[i+1]);
		while(scanf("%c",&c[i+1])!=EOF,c[i+1]==' ');}
		if(c[i]=='*')
		{
			n[i]=n[i]*n[i+1];
			c[i]=c[i+1];
			if(c[i]=='\n')
			{
				if(i==0)
					return n[i];
				if(i>0)
				{
					sign=1;
					i--;
				}

			}
			continue;
		}
		if(c[i]=='/')
		{
			n[i]=n[i]/n[i+1];
			c[i]=c[i+1];
			if(c[i]=='\n')
			{
				if(i==0)
					return n[i];
				if(i>0)
				{
					sign=1;
					i--;
				}

			}
			continue;
		}
		if(c[i]=='-')
		{
			c[i]='+';
			n[i+1]=-n[i+1];
		}
		if(c[i]=='+')
		{
			if(c[i+1]=='+'||c[i+1]=='-')
			{
				n[i]=n[i]+n[i+1];
				c[i]=c[i+1];
				continue;
			}
			if(c[i+1]=='*'||c[i+1]=='/')
			{
				i++;
				continue;
			}
			if(c[i+1]=='\n')
			{
				n[i]+=n[i+1];
				c[i]=c[i+1];
				if(i>0)
				{
					i--;
					sign=1;
				}
				else
					return n[i];
			}

		}	

	}
}