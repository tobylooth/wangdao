#include<stdio.h>
int main()
{
	char c;
		while(scanf("%c",&c)!=EOF)
		{
			int temp=c-'a';
			if(temp<0)
				printf("\n");
			else if (temp<17)
				printf("%d",(temp+3)/3+1);
			else if (temp<19)
				printf("7");
			else if(temp<22)
				printf("8");
			else if(temp<27)
				printf("9");
		}	
	return 0;
}