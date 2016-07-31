#include<stdio.h>
#include<string.h>
int main()
{
	int n, i, j;
	char one[1000], temp;
	scanf("%d", &n);
	getchar();
	for (j = 0; j < n; j ++)
	{
		double tempp = 0, tempi = 0, tempu = 0, num = 0;
		printf("Problem #%d\n", j + 1);
		int k = 2;

		while(k--)
		{
			for(i = 0; (one[i] = getchar()) != '='; i ++);
			scanf("%lf", &num);
			scanf("%c", &temp);
			if (temp == 'M')
				num *= 1000000;
			if (temp == 'm')
				num *= .001;
			if (temp == 'k')
				num *= 1000;
			if((one[i - 1]) == 'U')
				tempu = num;
			else if((one[i - 1]) == 'I')
				tempi = num;
			else if((one[i - 1]) == 'P')
				tempp = num;
		}

		if(tempi > 0 && tempu > 0)
			printf("P=%.2lfW\n",(tempu * tempi));
		else if(tempp > 0 && tempu > 0)
			printf("I=%.2lfA\n",(tempp / tempu));
		else if(tempp > 0 && tempi > 0)
			printf("U=%.2lfV\n",(tempp / tempi));
		printf("\n");
		tempp = tempu = tempi = 0;
	}
	return 0;
}
