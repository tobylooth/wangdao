#include<stdio.h>
int main(int argc, char const *argv[])
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF,a!=0||b!=0)
	{
		int minx,miny,maxx,maxy;
		minx=maxx=a,miny=maxy=b;
		int x,y;
		while(scanf("%d%d",&x,&y)!=EOF,x!=0||y!=0)
		{
			if(x<minx)
				minx=x;
			if(x>maxx)
				maxx=x;
			if(y<miny)
				miny=y;
			if(y>maxy)
				maxy=y;
		}
		printf("%d %d %d %d\n",minx,miny,maxx,maxy );

	}
	return 0;
}