
/*
	Author:Gneveek
	Data: 2011-10-1
	Source: UVa 457 - Linear Cellular Automata
*/
#include <stdio.h>
#include <string.h>
int dna[10],jun[50][45];
int main()
{
	//freopen("D:\\data.in","r",stdin);
	//freopen("D:\\data2.out","w",stdout);
	int n,i,j,temp;
	scanf("%d",&n);
	while(n--)
	{
		for(i=0; i<10; i++)
			scanf("%d",&dna[i]);

		memset(jun,0,sizeof(jun));
		jun[0][20] = 1;
		for(i=1; i<50; i++)
		{
			for(j=1; j<41; j++)
			{
				temp = jun[i-1][j-1] + jun[i-1][j] + jun[i-1][j+1];
				jun[i][j] = dna[temp];
			}
		}
		for(i=0; i<50; i++)
		{
			for(j=1; j<41; j++)
			{
				switch (jun[i][j])
				{
				case 0:
					putchar(' ');
					break;
				case 1:
					putchar('.');
					break;
				case 2:
					putchar('x');
					break;
				case 3:
					putchar('W');
					break;
				}
			}
			putchar('\n');
		}
		if(n>0)
			putchar('\n');
	}
	return 0;
}
