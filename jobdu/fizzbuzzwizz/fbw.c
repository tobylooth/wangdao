#include<stdio.h>
int main(){
	int a[3];char *c[3]={"Fizz","Buzz","Whizz"};
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	for (int i = 1,sign=0; i <= 100; ++i,sign=0)
		if(i/10==a[0]||i%10==a[0])
			printf("%s\n",c[0]);
		else{
			for(int j=0;j<3;j++)
				i%a[j]==0?printf("%s",c[j] ):sign++;
			sign==3?printf("%d\n",i ):printf("\n");}
	return 0;}