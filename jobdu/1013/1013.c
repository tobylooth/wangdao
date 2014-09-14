#include<stdio.h>
#include<string.h>
struct record
{
	char id[16];
	char arrive[9];
	char leave[9];
	/* data */
};
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m);
			struct record r[m];
			for(int j=0;j<m;j++)
				scanf("%s%s%s",r[j].id,r[j].arrive,r[j].leave);
			int first=0,last=0;
			for(int j=1;j<m;j++)
			{
				if(strcmp(r[first].arrive,r[j].arrive)>0)
					first=j;
				if(strcmp(r[last].leave,r[j].leave)<0)
					last=j;
			}
			printf("%s %s\n",r[first].id,r[last].id );
		}
	}
	return 0;
}