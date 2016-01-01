#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include<iostream> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i;
	for(i = 2;i<=n;i++)
	{
		int j,yn = 0;
		for(j = 2;j<=i/2;j++)
		{
			if(i%j==0)
			yn = 1;
		}
		if(yn == 0)
		cout<<i<<" ";	
	}
	return 0; 
} 
