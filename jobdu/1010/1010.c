#include<stdio.h>
#define N 10
int main(int argc, char const *argv[])
{
	char s[N];int a=0,b=0,swi=0;
	while(scanf("%s",s)!=EOF)
	{
		int temp=0;
		switch(s[0])
		{
			case '+':swi=1;break;
			case '=':
			if(a+b!=0){
						printf("%d\n",a+b );
						a=b=swi=0;break;}	
			else
				return 0;
			case 'z':temp=0;break;
			case 'o':temp=1;break;
			case 't':s[1]=='w'?(temp=2):(temp=3);break;
			case 'f':s[1]=='o'?(temp=4):(temp=5);break;
			case 's':s[1]=='i'?(temp=6):(temp=7);break;
			case 'e':temp=8;break;
			case 'n':temp=9;break;
		}
		swi==0?(a=a*10+temp):(b=b*10+temp);
	}
	return 0;
}