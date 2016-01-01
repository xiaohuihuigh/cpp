#include<iostream>
using namespace std;
int main()
{
	int i,a,b,c;
	for(i = 1;;i++)
	{
		if(i%8 == 1&&i/8%8 == 1)
		{
			if(i/8/8%8 == 7)
			{
				a = i/8/8/8;
				if(i%17 == 4&&i/17%17 == 15)
				{
					b = i/17/17;
					if(2*a == b)
					break;
				}
			}
		}
	}
	cout<<i;
	return 0;
 } 
