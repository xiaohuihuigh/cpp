#include<stdio.h>
int x,y,z;
void geshu(int a1,int b1,int c1){
	int i,j,k;
	for(i = 0; i <= 100/a1;i++)
		for(j = (100-a1*i)/b1;j >= 1;j--)
			for(k=1;k <= (100-a1*i - b1*j)/c1;k++)
			if(a1*i + b1*j + c1 * k == 100 && i + j + 3 * k == 100)
			{	
				x = i;
				y = j;
				z = 3*k;
				printf("cock=%d,hen=%d,chicken=%d\n",x,y,z);
			}
	
}
int main()
{
	int a,b,c;
		a = 5;b = 3,c = 1;
		geshu(a,b,c);
	return 0;
}
