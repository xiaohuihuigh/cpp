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
	int i,g,s,b,q,w;
	for(i = 95860;;i++)
	{
		g = i%10;
		s = i/10%10;
		b = i/100%10;
		q = i/1000%10;
		w = i/10000;
		if(i == g*10000+s*1000+b*100+q*10+w)
		{
			cout<<i;
			break;
		}
	}
	return 0; 
}
