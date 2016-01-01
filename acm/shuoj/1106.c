#include<stdio.h>
int main()
{
	int i,n,m;
	scanf("%d",&n);
	printf("%d*%d*%d=%d=%d",n,n,n,n*n*n,n*n-n+1);
	m = n*n-n+1;
	for(i = 1;i<n;i++)
	{
		m+=2;
		printf("+%d",m);
	}
	return 0;
}
