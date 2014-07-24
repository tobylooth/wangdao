#include<stdio.h>
#define N 100
int main(int argc, char const *argv[])
{
	char c,z[N],o[N],j[N];
	int countz=0,counto=0,countj=0;
	while(scanf("%c",&c)!=EOF,c!='E')
	{
		if(c=='Z')
			z[countz++]=c;
		if(c=='O')
			o[counto++]=c;
		if(c=='J')
			j[countj++]=c;
		if(c=='\n')
		{
			for (int i = 0; i <100; ++i)
			{
				if(i<countz)
					printf("%c",z[i]);
				if(i<counto)
					printf("%c",o[i] );
				if(i<countj)
					printf("%c",j[i] );
			}
			printf("\n");
			countz=counto=countj=0;
		}
	}

	return 0;
}