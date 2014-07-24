#include<stdio.h>
#include<string.h>
struct student
{
	int ID;
	char name[9];
	int score;
};
int main(int argc, char const *argv[])
{
	int N,C,count=1;
	int sort1(struct student s[],int n);
	int sort2(struct student s[],int n);
	int sort3(struct student s[],int n);
	while(scanf("%d%d",&N,&C)!=EOF,N!=0)
	{
		struct student stu[N];
		for(int i=0;i<N;i++)
		scanf("%d%s%d",&stu[i].ID,stu[i].name,&stu[i].score);
		if(C==1)
			sort1(stu,N);
		if(C==2)
			sort2(stu,N);
		if(C==3)
			sort3(stu,N);
			printf("Case %d:\n",count++ );
			for (int i = 0; i < N; ++i)
				printf("%06d %s %d\n",stu[i].ID,stu[i].name,stu[i].score );

	}
	return 0;
}
int sort1(struct student s[],int n)
{
	int i,j;
	struct student temp;
	temp=s[0];
	i=0;j=n-1;
	if(j>0)
	{
	while(i<j)
	{
		for(;j>i;j--)
			if(s[j].ID<temp.ID)
			{
				s[i]=s[j];
				break;
			}
		for(;i<j;i++)
			if(s[i].ID>temp.ID)
			{
				s[j]=s[i];
				break;
			}
	}
	s[i]=temp;
	sort1(s,i);
	sort1(s+i+1,n-i-1);
}
return 0;
}
int sort2(struct student s[],int n)
{
	int i,j;
	struct student temp;
	i=0;j=n-1;
	temp=s[0];
	if(j>0)
	{
		while(i<j)
		{
			for(;j>i;j--)
			{
				if((strcmp(s[j].name,temp.name)<0))
				{
					s[i]=s[j];break;
				}
				if((strcmp(s[j].name,temp.name)==0))
				{
					if(s[j].ID<temp.ID)
					{
						s[i]=s[j];break;
					}
				}
			}
			for(;i<j;i++)
			{
				if((strcmp(s[i].name,temp.name)>0))
				{
					s[j]=s[i];break;
				}
				if((strcmp(s[i].name,temp.name)==0))
				{
					if(s[i].ID>temp.ID)
					{
						s[j]=s[i];break;
					}
				}
			}
		}
		s[i]=temp;
		sort2(s,i);
		sort2(s+i+1,n-i-1);
	}
return 0;
}
int sort3(struct student s[],int n)
{
	int i,j;
	struct student temp;
	i=0;j=n-1;
	temp=s[0];
	if(j>0)
	{
		while(i<j)
		{
			for(;j>i;j--)
			{
				if(s[j].score<temp.score)
				{
					s[i]=s[j];break;
				}
				if(s[j].score==temp.score)
				{
					if(s[j].ID<temp.ID)
					{
						s[i]=s[j];break;
					}
				}
			}
			for (;i<j;i++)
			{
				if(s[i].score>temp.score)
				{
					s[j]=s[i];break;
				}
				if(s[i].score==temp.score)
				{
					if(s[i].ID>temp.ID)
					{
						s[j]=s[i];break;
					}
				}
			}

		}
		s[i]=temp;
		sort3(s,i);
		sort3(s+i+1,n-i-1);
	}
	return 0;
}
