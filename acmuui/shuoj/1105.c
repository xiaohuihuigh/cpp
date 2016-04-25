#include<stdio.h>
#include<string.h>
int main()
{
	char a[110];
	gets(a);
	int l,i;
	l = strlen(a);
	for( i = 0;i<l;i++)
	{
		a[l+i] = a[l-i-1];
	}
	puts(a);
	return 0;
}
