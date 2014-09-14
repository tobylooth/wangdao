#include<stdio.h>
int main(int argc, char const *argv[])
{
	int N;
	while(scanf("%d",&N)!=EOF,N>0)
	{
		int score[N],line,num=0;
		for (int i = 0; i < N; ++i)
			scanf("%d",&score[i]);
		scanf("%d",&line);
		for (int i = 0; i < N; ++i)
			if(score[i]==line)
				num++;
		printf("%d\n",num );
	}
	return 0;
}