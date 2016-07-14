
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#include<stdio.h>
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define M_PI 3.14159265358979323846
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define MAX_V 10101
#define maxn 567
#define lowbit(X) (X & (-X))
#include<ctime>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;

int t = 0,i = 0;
char a[10000][100];
int flag[10000];
void dfs( int k)
{
	char c = a[k][strlen(a[k])-1];
	if(c == 'm')
	{
		t = 1;
		return;
	}
	else
	{
		REP(z,i)
		{
			if(a[z][0] == c&&flag[z] == 0)
			{
				flag[z] = 1;
				dfs(z);
			}
		}
	}
}


int main()
{
	while(gets(a[i++]))
	{
		//cout<<a[i-1];
		if(a[i-1][0] =='0')
		{
			memset(flag,0,sizeof(flag));
			REP(j,i-1)
			{
				if(a[j][0] == 'b')
				{
					//cout<<a[j];
					flag[j] = 1;
					dfs(j);
				}
			}
			if(t)
				cout<<"Yes."<<endl;
			else
				cout<<"No."<<endl;
			t = 0;
			memset(a,'\0',sizeof(a));
			i = 0;
		}
	}
}

