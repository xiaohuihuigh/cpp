 
#include<stdio.h>

int main()
{
	int a[12][12];
	int t,sum = 0,i,j;
	scanf("%d",&t);
	for(i = 0;i<t;i++)
	for(j = 0;j<t;j++)
	{
		scanf("%d",&a[i][j]);
	}
	for(i = 0;i<t;i++)
	{
		sum = sum +a[i][i];
	}
	for(i = 0;i<t;i++)
	{
		sum = sum +a[i][t-1-i];
	}
	if(t%2!=0)
	{
		sum = sum - a[t/2][t/2];
	}
	printf("%d",sum);
	
}
