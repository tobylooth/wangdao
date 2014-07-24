#include<stdio.h>
#include<string.h>
struct Curse
{
	char cur[21];
	char func[81];
	int curlen;
	int funclen;
}curse[100000];
int main(int argc, char const *argv[])
{
	char a;
	int n=0;
	while(scanf("%c",&a)!=EOF)
	{
		int m=0;
		if(a=='@')
		{
			char a1[5];
			scanf("%s",a1);
			if(strcmp(a1,"END@")==0)
				break;
		}
		if(a=='[')
		{
			while(scanf("%c",&a)!=EOF,a!=']')
			{
				curse[n].cur[m]=a;
				m++;
			}
			curse[n].curlen=m;
			m=0;
		}
		if(a==']')
		{
			scanf("%c",&a);
			while(scanf("%c",&a)!=EOF,a!='\n')
			{
				curse[n].func[m]=a;
				m++;
			}
			curse[n].funclen=m;
			m=0;
		}
		n++;
	}
	int N;
	scanf("%d",&N);
	char temp[81],c;
	for (int i = 0; i < N; ++i)
		{   int count=0;
		    while(scanf("%c",&c)!=EOF,c==' '||c=='\n');
			if(c=='[')
				{
					while(scanf("%c",&c)!=EOF,c!=']')
					{
						temp[count]=c;
						count++;
					}
					int sign=-1;
					for(int j=0;j<n;j++)
					{
						if(count==curse[j].curlen)
						{	
							int k=0;
							for(k=0;k<count;k++)
								if(temp[k]!=curse[j].cur[k])
									break;
							if(k==count)
							{
								sign=j;
								break;
							}
						}
					}
					if(sign>-1)
					{
						for(int j=0;j<curse[sign].funclen;j++)
							printf("%c",curse[sign].func[j] );
						printf("\n");
					}
					else
						printf("what?\n");
				}
			else
				{
					temp[count]=c;
					count++;
					while(scanf("%c",&c)!=EOF,c!='\n')
					{
						temp[count]=c;
						count++;
					}
					int sign=-1;
					for(int j=0;j<n;j++)
					{ 
						if(count==curse[j].funclen)
						{	
							int k=0;
							for(k=0;k<count;k++)
								if(temp[k]!=curse[j].func[k])
									break;
							if(k==count)
							{
								sign=j;
								break;
							}
						}
					}
					if(sign>-1)
					{
						for(int j=0;j<curse[sign].curlen;j++)
							printf("%c",curse[sign].cur[j] );
						printf("\n");
					}
					else
						printf("what?\n");
				}
		}
	return 0;
}