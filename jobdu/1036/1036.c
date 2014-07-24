#include<stdio.h>
int main(){
	int n,x,y,z;
	while(scanf("%d",&n)!=EOF){
		scanf("%d%d%d",&x,&y,&z);
		int a=0,b=0,price=0,sign=0;
		for (int i =1; i <=9; i++)
			for(int j=0;j<=9;j++)
				if((i*10000+x*1000+y*100+z*10+j)%n==0){
					a=i;
					b=j;
					price=(i*10000+x*1000+y*100+z*10+j)/n;
					sign=1;}
		sign==0?printf("0\n"):printf("%d %d %d\n",a,b,price );}
	return 0;}