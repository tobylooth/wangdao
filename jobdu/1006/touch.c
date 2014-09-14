#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	char *ac="Accepted",*wr="Wrong Anwser";
	char str[1002];
    int nz=0,nj=0,n=0;
    int a=0,b=0,c=0;
	while(scanf("%s",str)!=EOF)
	{
		int lenth=strlen(str);
		char *p=str;
		
		while(p-str<lenth)
		{
			if(*p=='o')
				{
					if(nz==0&&nj==0)
						a++;
					else if(nz==1&&nj==0)
						b++;
					else if(nz==1&&nj==1)
						c++;
					else
						n++;

				}
			else if(*p=='z')
				nz++;
			else if(*p=='j')
				nj++;
			else 
				n++;
			p++;
		}

				if(b<1||n>0)
					printf("%s\n",wr);
				else
					{
                                                                                             for(int i=b;i>1;--i)
                                                                                               {c=c-a;}
						if(a==c)
							printf("%s\n",ac);
						else
							printf("%s\n",wr);
					}
	}
	return 0;
}