#include<stdio.h>
int stack[501][501];
int submit(int n)
{
	for (int i = 1; i <= n; ++i)
		stack[i][0]=1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j<=i; ++j)
			stack[i][j]=(stack[i-1][j]+stack[i][j-1])%1000000007;
	return stack[n][n];

}
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF)
	if((n%2)==0?printf("%d\n",submit(n/2)):printf("%d\n",0 ));
	/* code */
	return 0;
}