#include<stdio.h>
int main()
{
	int j,n,i;
	long long sum1 = 1,sum2 = 0;
	scanf("%d",&n);
	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=i;j++)
		sum1 = sum1*j;
		sum2 = sum2+sum1;
		sum1 = 1;
	 } 
	 printf("%lld",sum2);
	 return 0;
}
