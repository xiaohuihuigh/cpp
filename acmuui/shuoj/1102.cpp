#include<iostream>
using namespace std;
int main()
{
	int i;
	for(i = 0;i<40;i++)
	{
		if(i%2 != 0 &&i%5 != 0)
		cout<<i<<"/40,";
	}
	return 0;
}
