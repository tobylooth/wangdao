#include<stdio.h>
#include<string.h>
#define N 803 
int result[N];
int Additon(int a[],int b[])
{
	int sign1=0,sign2=0;
	if(a[0]==1)
		for (int i = 1; i < N; ++i)
			a[i]=-a[i];
	if(b[0]==1)
		for(int i=1;i<N;i++)
			b[i]=-b[i];
	for (int i = N-1; i >0; i--)
		result[i]=a[i]+b[i];
	if(a[0]==b[0])
	{
		if(a[0]==1)
			for(int j=1;j<N;j++)
				result[j]=0-result[j];
		for(int i=N-1;i>0;i--)
		{	sign2=(result[i]+sign1)/10;
			result[i]=(result[i]+sign1)%10;
			sign1=sign2;
		}
		result[0]=a[0];
	}
	else
	{
		int temp=1;
		for(temp=1;result[temp]==0&temp<N;temp++);
			if(result[temp]<0)
			{
				result[0]=1;
				for(int j=N-1;j>0;j--)
				{
					if(result[j]+sign1>0)
					{
						result[j]=10-(result[j]+sign1);
						sign1=1;
					}	
					else
					{
						result[j]=-(result[j]+sign1);
						sign1=0;
					}
				}		
			}
			else
			{
				result[0]=0;
				for(int j=N-1;j>0;j--)
				{
					if(result[j]+sign1<0)
					{
						result[j]=10+(result[j]+sign1);
						sign1=-1;
					}
					else
					{
						result[j]=result[j]+sign1;
						sign1=0;
					}
				}
			}
	}
	if(a[0]==1)
		for (int i = 1; i < N; ++i)
			a[i]=-a[i];
	if(b[0]==1)
		for(int i=1;i<N;i++)
			b[i]=-b[i];		
}
int Subtrac(int a[],int b[])
{
	b[0]=(b[0]+1)%2;
	Additon(a,b);
	b[0]=(b[0]+1)%2;
}
int Multi(int a[],int b[])
{
	int temp[N]={0},sign1=a[0],sign2=b[0];
	a[0]=b[0]=0;
	for (int i = N-1; i >400 ; i--)
		for(int j=N-1;j>400;j--)
			result[i+j-802]+=a[i]*b[j];
	Additon(result,temp);
	if(sign1==sign2)
		result[0]=0;
	else
		result[0]=1;
	a[0]=sign1;
	b[0]=sign2;
}
int output(int a[])
{
	int count=1;
	if(a[0]==1)
		printf("-");
	while(a[count]==0&&count<N)
		count++;
	if(count==N)
		printf("0");
	else
		for (int i = count; i < N; ++i)
			printf("%d",a[i] );
	printf("\n");

}
int main(int argc, char const *argv[])
{

	char c1[402],c2[402];
	int ArrA[N],ArrB[N];
	while(scanf("%s%s",c1,c2)!=EOF)
	{
		for (int i = 0; i < N; ++i)
			ArrA[i]=ArrB[i]=0;
		int counta=0,countb=0;
		counta=strlen(c1);
		countb=strlen(c2);
		for(int i=N-1,j=counta-1;j>=0;j--,i--)
			if(c1[j]!='-')
				ArrA[i]=c1[j]-'0';
			else
				ArrA[0]=1;
		for(int i=N-1,j=countb-1;j>=0;i--,j--)
			if(c2[j]!='-')
				ArrB[i]=c2[j]-'0';
			else
				ArrB[0]=1;
		for(int i=0;i<N;i++)
			result[i]=0;
		Additon(ArrA,ArrB);
		output(result);
		for(int i=0;i<N;i++)
			result[i]=0;
		Subtrac(ArrA,ArrB);
		output(result);
		for(int i=0;i<N;i++)
			result[i]=0;
		Multi(ArrA,ArrB);
		output(result);
	}
	return 0;
}