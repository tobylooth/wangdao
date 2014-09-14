#include<stdio.h>
int main(int argc, char const *argv[])
{
	int s;
	while(scanf("%d",&s)!=EOF)
	{
		struct coordinate
		{
			double x;
			double y;
		}c[s];
		for (int i = 0; i < s; ++i)
			scanf("%lf%lf",&c[i].x,&c[i].y);
		int max=1,n=1;
		if(s>2)
		{
			for (int i = 0; i < s-1; ++i)
			{
				n=2;
				for (int a = i+1; a< s-1; ++a)
				{
					if((c[i].x==c[a].x)&&(c[i].y==c[a].y))
					{
						n++;
						if(n>max)
							max=n;
						continue;
					}
					else
					for (int j =a+1; j < s; ++j)
						if((c[a].y-c[i].y)*(c[j].x-c[i].x)==(c[a].x-c[i].x)*(c[j].y-c[i].y))
							n++;		
					if(n>max)
							max=n;	
					n=2;
				}	
			}
			printf("%d\n",max);
		}
		else
			printf("%d\n",s);
	}
	return 0;
}