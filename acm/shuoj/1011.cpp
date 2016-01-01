#include<stdio.h>
int main(){
	int n,k,i,j,*p,*sum;
	scanf("%d%d",&n,&k);
	p = (int*)malloc(n*sizeof(int));
	for(i = 0;i < n;i++)
		scanf("%d",p+i);
	for(i = 0;i < n;i++)
		printf("%d",*(p+i));
	free(p);
}
