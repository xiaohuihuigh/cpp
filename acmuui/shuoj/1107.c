#include<stdio.h>
int main()
{
	int a[11];
	int j,i,b;
	for(i = 0;i<10;i++)
	scanf("%d",&a[i]);
	for(i = 0;i<10;i++)
	for(j = i;j<10;j++)
	{
		if(a[i]<a[j])
		{
			b = a[i];
			a[i] = a[j];
			a[j] = b;
		}
		
	}
	printf("%d",a[0]); 
	for(i = 1;i<10;i++)
	printf(" %d",a[i]);
	return 0;
}
