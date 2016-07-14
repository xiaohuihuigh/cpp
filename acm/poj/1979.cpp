
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
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;
int w,h;
 char a[25][25];
int dfs(int i,int j)
{
	if(i<0 || i>=h || j<0 || j>=w) return 0;
    if(a[i][j]=='#')return 0;
    a[i][j]='#';
    int t;
    t=1+dfs(i-1,j)+dfs(i+1,j)+dfs(i,j+1)+dfs(i,j-1);
    return t;
}

int main()
{
	int c,b,i,j;
	while(cin>>w>>h&&w!=0&&h!=0)
	{
		memset(a,'#',sizeof(a));
		REP(i,h)
		{
		REP(j,w)
		{
			cin>>a[i][j];
			if(a[i][j] == '@')
			{
			c = i;b = j;
			}
		}
		}
		int n;

		n = dfs(c,b);

		cout<<n<<endl;

	}
	return 0;
}
