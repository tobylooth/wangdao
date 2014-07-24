#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	int prime[25],n=0;
	for (int i = 2; n<25; ++i){
		int sign=0;
		for(int j=2;j<i;j++){
			if(i%j==0){
					sign++;
					break;
				}
		}
		if(sign==0){
			prime[n]=i;
			n++;
		}
	}
	int convert(char s[],int arr[]);
	char sa[100],sb[100];
	while(scanf("%s%s",sa,sb)!=EOF){
		if(!((strcmp(sa,"0"))&&(strcmp(sb,"0"))))
			break;
		int A[26]={0},B[26]={0};
		convert(sa,A);
		convert(sb,B);
		for (int i = 25; i >0; --i){
			int temp=0;
			A[i]=A[i]+B[i];
			if(A[i]>=prime[25-i]){
				temp=A[i]/prime[25-i];
				A[i-1]=A[i-1]+temp;
				A[i]=A[i]%prime[25-i];
			}
		}
		int t=0;
		for (int i = 0; i < 26; ++i){
			if(A[i]==0)
				t++;
			else
				break;
		}
		for (int i = t; i < 26; ++i){
			if(i==25)
				printf("%d\n",A[i] );
			else
				printf("%d,",A[i] );
		}
	}
	return 0;
}
int convert(char s[],int arr[]){
	int len=strlen(s);
	int qoute=0;
	for(int i=0;i<len;i++)
		if(s[i]==',')
			qoute++;
	int a=26-qoute-1;
	for (int i = 0; i < len; ++i){
			if(s[i]==','){
					arr[a]=arr[a]/10;
					a++;
				}
			else{
				arr[a]=(arr[a]+(s[i]-'0'))*10;
				}
			if(i==len-1)
				arr[a]=arr[a]/10;
		}
	return 0;
}