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
	int n,i;
	cin>>n;
	for(i = 2;i<=n/2;i++)
	{
		if(n%i == 0)
		{
			cout<<"0";
			return 0;
		} 
	}
	cout<<"1";
	return 0; 
}
