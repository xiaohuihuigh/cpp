#include<stdio.h>
#include<string.h>
int time(char a[])
{
	int time ;
	time = (int)((a[7]-'0')+(a[6]-'0')*10+(a[4]-'0'+(a[3] - '0')*10)*60+(a[1] - '0'+(a[0]-'0')*10)*3600);
	return time;
}
int main()
{
	struct ticou{
		char name[3];
		char time[20];
	};
	struct ticou ticous[100];
	char h[10],h1[10] = {"happy"},h2[10] = {"unhappy"};
	int t,n,i,j,k = 1;
	scanf("%d",&t);
	while(t--)
	{
		double a,b;
		int time77 = 0,timecc = 0,count77 = 0,countcc = 0;
		scanf("%d",&n);
		for(i = 0; i<n;i++)
		{
			scanf("%s",ticous[i].name);
			scanf("%s",ticous[i].time);
			}
		for(i = 1;i<n;i++)
		{
			if(ticous[i].name[0] == 'c')
			{
				timecc = timecc+ticous[i].time - ticous[i-1].time;
			}
			if(ticous[i].name[0] == '7')
			{
				time77 = time77+ticous[i].time - ticous[i-1].time;
			}
		}
		for(i = 0;i < n ;i++)
		{
			if(ticous[i].name[0] == 'c')
			countcc += 1;
			if(ticous[i].name[0] == '7')
			count77 += 1;
			
		}
		if(timecc == 0||countcc == 0)
			a= 0;
		else 
		{
			a = (double)time77/(double)timecc;
			b = (double)count77/(double)countcc;
		}
		if(a>=0.5&&a<=2&&b>=0.5&&b<=2)
		strcpy(h,h1);
		else
		strcpy(h,h2);
		printf("Case %d:\n",k++);
		printf("%d %d %d %d ",time77,timecc,count77,countcc);
		puts(h) ;
	}
	return 0;
	
}
