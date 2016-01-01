#include<stdio.h>
int main()
{
	int a[10000];
	int i;
	for(i = 0;;i++)
	{
		scanf("%d",&a[i]);
		if(a[i] == -1)
		break; 
	}
	int k;
	for(k = 0;k<i;k++)
	{
		if(a[0]<a[k])
		a[0] = a[k];
	}
	printf("%d",a[0]);
	return 0;
}
