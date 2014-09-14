#include<stdio.h>
#define BIMAX 1000
#define ITEMAX 600
int main(int argc, char const *argv[])
{
	float Q;
	int N; 
	int sort(float a[],int n);
	while(scanf("%f%d",&Q,&N)!=EOF,N>0)
	{
		int m,CtValid=0;
		float Valid[N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d",&m);
			char GoodType[m],temp;
			float num[m],Vsum=0;
			int VSign=0;
			for(int j=0;j<m;j++)
			{
				scanf(" %c:%f",&GoodType[j],&num[j]);
				if(GoodType[j]!='A'&&GoodType[j]!='B'&&GoodType[j]!='C')
					VSign=1;
				if(num[j]>ITEMAX)
					VSign=1;
				Vsum+=num[j];
			}
			if(Vsum>BIMAX||Vsum>Q)
				VSign=1;
			if(VSign==0)
			{
				Valid[CtValid]=Vsum;
				CtValid++;
			}
		}
		sort(Valid,CtValid);
		float max=Valid[0];
		if(CtValid<1)
			max=0;
		else
		for (int i = 0; i < CtValid; i++)
		{
			float maxtemp=0;
			for (int j=i+1;j<CtValid; ++j)
			{
				maxtemp=Valid[i];
				for(int t=j;t<CtValid;t++)
				{
					if((maxtemp+Valid[t])<=Q)
					{
						maxtemp+=Valid[t];
						if(maxtemp>max)
							max=maxtemp;
					}
					else
						if(maxtemp>max)
							max=maxtemp;

				}
			}
			if(max==Q)
				break;
		}
		printf("%0.2f\n",max );
	}
	return 0;
}
int sort(float a[],int n)
{
	int i=0,j=n-1;
	float value;
	value=a[0];
	if(n>1)
	{
		while(i<j)
		{
			for(;j>i;j--)
				if(a[j]>value)
				{
					a[i]=a[j];
					break;
				}
			for(;i<j;i++)
				if(a[i]<value)
				{
					a[j]=a[i];
					break;
				}
		}
		a[i]=value;
		sort(a,i);
		sort(a+i+1,n-i-1);
	}
}