#include<stdio.h>
#define M 101
struct recorde
{
	int ShipID;
	int Time;
	int sign;
}Start[M];
int main(int argc, char const *argv[])
{
	for (int i = 0; i < M; ++i)
	{
		Start[i].ShipID=0;
		Start[i].Time=0;
		Start[i].sign=0;
	}
	int id,hour,minitue,s=0,count=0,ti=0;
	char statue;
	float avgti=0;
	while(scanf("%d",&id)!=EOF,id!=-1)
	{
		while(scanf("%c",&statue)!=EOF,statue==' ');
		scanf("%d:%d",&hour,&minitue);
		if(statue=='S')
		{
			for (int i = 0; i < s; ++i)
			{
				if(Start[i].ShipID==id)
					if(Start[i].sign==0)
						Start[i].sign=-1;
			}
			Start[s].ShipID=id;
			Start[s].Time=hour*60+minitue;
			s++;
		}
		if(statue=='E')
		{
			for (int i = 0; i < s; ++i)
			{
				if(Start[i].ShipID==id)
					if(Start[i].sign==0)
					{
						count++;
						ti+=(hour*60+minitue-Start[i].Time);
						Start[i].sign=-1;
						break;
					}
			}
		}
		if(id==0)
		{
			if(count!=0)
			avgti=(float)ti/(float)count;
			printf("%d %.0f\n",count,avgti );
			for (int i = 0; i < M; ++i)
			{
				Start[i].ShipID=0;
				Start[i].Time=0;
				Start[i].sign=0;
			}
			s=count=ti=avgti=0;
		}
	}
	return 0;
}