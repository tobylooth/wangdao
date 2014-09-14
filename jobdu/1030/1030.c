#include<stdio.h>
int happy,haptemp;
struct bginvite
{
	int h,l,t,sign;
};
int main(int argc, char const *argv[])
{
	int N;
	while(scanf("%d",&N)!=EOF,N>=0)
	{
		happy=0;haptemp=0;
		int hap(struct bginvite bg[],int n,int s);
		struct bginvite invi[N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d%d%d",&invi[i].h,&invi[i].l,&invi[i].t);
			invi[i].sign=0;
		}
		hap(invi,N,0);
		printf("%d\n",happy );
	}
	return 0;
}
int hap(struct bginvite bg[],int n,int s)
{
	for (int i = 0; i < n; ++i)
		if((bg[i].t-s)>=bg[i].l&&bg[i].sign==0)
			{
				haptemp+=bg[i].h;
				bg[i].sign=1;
				if(haptemp>happy)
					happy=haptemp;
				hap(bg,n,s+bg[i].l);
				haptemp-=bg[i].h;
				bg[i].sign=0;
			}
	return 0;
}