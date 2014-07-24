#include<stdio.h>
int main()
{
	int N,M,K;
	while(scanf("%d%d%d",&N,&M,&K)!=EOF)
	{
		struct application
		{
			float score[2];
			int choice[K];
			int rank;
			int asc;
		};
		int school[M][N];
		for (int i = 0; i < M; ++i)
		{
			scanf("%d",&school[i][0]);
			school[i][1]=0;
		}
		struct  application app[N],temp;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < 2; ++j)
				scanf("%f",&app[i].score[j]);
			for (int j = 0; j < K; ++j)
				scanf("%d",&app[i].choice[j]);
			app[i].rank=app[i].asc=i;
		}
		int count=N;
		while (count>1)
		{	
			for (int i = N-1; i > 0; --i)
			{
				float com1,com2;
				com1=(app[i].score[0]+app[i].score[1])/2;
				com2=(app[i-1].score[0]+app[i-1].score[1])/2;
				if(com1>com2)
				{
					temp=app[i];
					app[i]=app[i-1];
					app[i-1]=temp;
					app[i-1].asc=i-1;
					app[i].asc=i;
				}	
				else if(com1==com2)
				{
					if(app[i].score[0]>app[i-1].score[0])
					{
						temp=app[i];
						app[i]=app[i-1];
						app[i-1]=temp;
						app[i-1].asc=i-1;
						app[i].asc=i;
					}
					else if(app[i].score[0]==app[i-1].score[0])
						app[i-1].asc=app[i].asc=i-1;
				}
			/* code */
			}
			count--;
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < K; ++j)
			{
				int n,x;
				n=app[i].choice[j];
				x=school[n][1]+2;
				if(school[n][1]<school[n][0])
				{
					school[n][x]=i;
					school[n][1]++;
					break;
				}
				else 
				{
					if(app[i].asc==app[school[n][x-1]].asc)
					{
						school[n][x]=i;
						school[n][0]++;
						school[n][1]++;
						break;
					}
				}
				
			}
			
		}
		for (int i = 0; i < M; ++i)
		{
			int a,b;
			a=school[i][1];
			while(a>1)
			{
				for(int j=0;j<a-1;++j)
				{
					if(app[school[i][j+2]].rank>app[school[i][j+3]].rank)
					{
						b=school[i][j+2];
						school[i][j+2]=school[i][j+3];
						school[i][j+3]=b;
					}
				}
				a--;
			}

			/* code */
		}
		for (int i = 0; i < M; ++i)
		{
			if(school[i][1]>0)
			{
			for (int j = 0; j < school[i][1]-1; ++j)
					printf("%d ",app[school[i][j+2]].rank);
				printf("%d\n",app[school[i][school[i][1]+1]].rank);
			}
			else
				printf("\n");
		} 
	}
}