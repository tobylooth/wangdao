#include<stdio.h>
#include<string.h>
struct student
{
	char stuid[21];
	int  m;
	int  qid[10];
	int  score;
	/* data */
};
int main(int argc, char const *argv[])
{
	int N;
	while(scanf("%d",&N)!=EOF,N>0)
	{
		int M,G,n=0;
		scanf("%d%d",&M,&G);
		int sc[M+1];
		for (int i = 1; i <=M; ++i)
			scanf("%d",&sc[i]);
		struct student stu[N],temp;
		for (int i = 0; i < N; ++i)
		{
			scanf("%s%d",stu[i].stuid,&stu[i].m);
			stu[i].score=0;
			for (int j=0;j<stu[i].m;j++)
			{
				scanf("%d",&stu[i].qid[j]);
				stu[i].score+=sc[stu[i].qid[j]];
			}
			if(stu[i].score>=G)
				n++;
		}
		int a=N;
		for (int i = 1; i < N; ++i)
		{
			for (int j=0;j<a-i;j++)
			{
				if(stu[j].score<stu[j+1].score)
				{
					temp=stu[j+1];
					stu[j+1]=stu[j];
					stu[j]=temp;
				}
				else if(stu[j].score==stu[j+1].score)
				{
					if(strcmp(stu[j].stuid,stu[j+1].stuid)>0)
					{
						temp=stu[j+1];
						stu[j+1]=stu[j];
						stu[j]=temp;
					}
				}
			}
		}
		printf("%d\n",n );
		for(int i=0;i<n;i++)
		printf("%s %d\n",stu[i].stuid,stu[i].score );
	}
	return 0;
}