#include<stdio.h>
int main()
{
	int i,a,b;
	for(i = 1000;i<=9999;i++)
	{
		a = i%100;
		b = i/100;
		if((a+b)*(a+b) == i)
		printf("%d ",i);
		}	
	return 0;
 } 
