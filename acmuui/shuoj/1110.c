#include<stdio.h>
int main()
{
	int a[55]={1,1};
	int n;
	scanf("%d",&n);
	int i;
	printf("1");
	for(i = 1;i<n;i++)
	{
		if(i>=2)
		printf(" %d",a[i] = a[i-1]+a[i-2]);
		else 
		printf(" %d",a[i]); 
	}
	return 0;
}
