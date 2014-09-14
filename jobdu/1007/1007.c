#include<stdio.h>
struct COUNTRY
{
	double achiv[3];
	int rank[4];
	int firank[2];
	double gp;
	double medalp;
	/* data */
};
int main()
{
	int m,n;
	
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int opc[n];
		struct  COUNTRY  country[m];
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < 3; ++j)
				scanf("%lf",&country[i].achiv[j]);
			country[i].gp=country[i].achiv[0]/country[i].achiv[2];
			country[i].medalp=country[i].achiv[1]/country[i].achiv[2];
		}
		for (int i = 0; i < n; ++i)
			scanf("%d",&opc[i]);
		for (int i = 0; i < n; ++i)
		{	
			int temp[4]={0};
			for(int j=0;j<n;j++)
			{
				if(country[opc[i]].achiv[0]<country[opc[j]].achiv[0])
					temp[0]++;
				if(country[opc[i]].achiv[1]<country[opc[j]].achiv[1])
					temp[1]++;
				if(country[opc[i]].gp<country[opc[j]].gp)
					temp[2]++;
				if(country[opc[i]].medalp<country[opc[j]].medalp)
					temp[3]++;
			}
			for(int z=0;z<4;z++){
				country[opc[i]].rank[z]=temp[z]+1;
			}
			country[opc[i]].firank[0]=country[opc[i]].rank[0];
			country[opc[i]].firank[1]=1;
			for(int j=0;j<4;j++){
				if(country[opc[i]].rank[j]<country[opc[i]].firank[0])
				{
					country[opc[i]].firank[0]=country[opc[i]].rank[j];
					country[opc[i]].firank[1]=j+1;
				}
			}
		}
		for (int i = 0; i < n; ++i)
			printf("%d:%d\n", country[opc[i]].firank[0],country[opc[i]].firank[1]);
		
		printf("\n");
	}
	return 0;
}