#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	scanf("%s",a);
	int i,l = 0,sum = 0;
	l = strlen(a);
	for(i = 0;i<l;i++)
	{
		if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
		sum++;
	}
	printf("%d",sum);
	return 0; 
}
