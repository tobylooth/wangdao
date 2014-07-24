#include<stdio.h>
struct people
{
	char Child,Parent1,Parent2;
}people[26];
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 26; ++i)
	{
		people[i].Child='-';
		people[i].Parent1='-';
		people[i].Parent2='-';
	}
	int n,m;
	int FindChild(struct people p[],char a,char b);
	while(scanf("%d%d",&n,&m)!=EOF,n>0&&m>0)
	{
		for (int i = 0; i < n; ++i)
		{
			char str[4];
			scanf("%s",str);
			people[str[0]-'A'].Parent1=str[1];
			people[str[0]-'A'].Parent2=str[2];
			if(str[1]>='A'&&str[1]<='Z')
				people[str[1]-'A'].Child=str[0];
			if(str[2]>='A'&&str[2]<='Z')
				people[str[2]-'A'].Child=str[0];
		}
		char str[3];
		for (int i = 0; i < m; ++i)
		{
			scanf("%s",str);
			int CChild=0,CParent=0;
			CChild=FindChild(people,str[0],str[1]);
			if(CChild>0)
			{
				if(CChild==1)
					printf("parent\n");
				else
				{
					for(int j=3;j<=CChild;j++)
						printf("great-");
					printf("grandparent\n");
				}
			}
			else
			{
				CParent=FindChild(people,str[1],str[0]);
				if(CParent>0)
					if(CParent==1)
						printf("child\n");
					else
					{
						for(int j=3;j<=CParent;j++)
							printf("great-");
						printf("grandchild\n");
					}
				else
					printf("-\n");
			}
		}
	}
	return 0;
}
int FindChild(struct people p[],char a,char b)
{	int countchild=0;
	if(p[a-'A'].Child!='-')
		{
			if(p[a-'A'].Child==b)
				return 1;
			else
				countchild=FindChild(p,p[a-'A'].Child,b);
			if(countchild>0)
				countchild++;
			return countchild;
		}
	else
		return 0;
}
