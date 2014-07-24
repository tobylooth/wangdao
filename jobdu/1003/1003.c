#include<stdio.h>
#include<string.h>
int main()
{
	char stra[20],strb[20];
	while(scanf("%s %s",stra,strb)==2)
	{
		int  A=0,B=0,m=1;
		int lena=strlen(stra),lenb=strlen(strb);
		for (int i = 0; i < lena; i++)
		{	
			if (stra[lena-1-i]==',')
			{
				m=m/10;
				/* code */
			}
			else if (stra[lena-1-i]=='-')
			{
				A=-A;
				/* code */
			}
			else	A+=(stra[lena-i-1]-48)*m;
			m=m*10;
			/* code */
		}
		m=1;
		for (int i = 0; i < lenb; i++)
		{	
			if (strb[lenb-1-i]==',')
			{
				m=m/10;
				/* code */
			}
			else if (strb[lenb-1-i]=='-')
			{
				B=-B;
				/* code */
			}
			else	B+=(strb[lenb-i-1]-48)*m;
			m=m*10;
			/* code */
		}printf("%d\n",A+B);
	}
	return 0;
}
