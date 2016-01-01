#include<iostream>
using namespace std;
int main()
{
	int i,j,sum1 = 0,sum2 = 0,n;
	for(i = 2;i<=3000;i++) 
	{
		for(j = 1;j<=i/2;j++)
		{
			if(i%j == 0)
			{
				sum1 = sum1 + j;
			}
		}
		for(j = 1;j<= sum1/2;j++)
		{
			if(sum1%j == 0)
			{
				sum2 = sum2 + j;
			}
		}
		if(sum2 == i&& i<sum2)
		cout<<"("<<i<<","<<sum1<<")";
		sum1 = 0;
		sum2 = 0;
	}
	return 0;
}
