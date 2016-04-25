#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	char*p;
	int l,i;
	gets(p);
	l = strlen(p);
	for(i = 0;i<l;i++)
	if(*(p+i)>='A'&&*(p+i)<='Z')
	*(p+i) = *(p+i)+'a'-'A';
	puts(p);
	return 0;
 } 
