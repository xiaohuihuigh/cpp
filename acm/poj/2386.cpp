
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
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;

int n,m;
char maps[110][110];
int dir[8][2] = {{1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
void dfs(int i,int j)
{
	if(i<0||i>=n||j<0||j>=m||maps[i][j] == '.')return;
	maps[i][j] = '.';
	REP(k,8)
	dfs(i+dir[k][0],j+dir[k][1]);
	return ;
}
int main()
{
	cin>>n>>m;
	REP(i,n)
	REP(j,m)
		cin>>maps[i][j];
	int t = 0;
	REP(i,n)
	REP(j,m)
	{
		if(maps[i][j] == 'W')
		{
			t++;
			dfs(i,j);
		//	cout<<t;
		}
	}
	cout<<t;
	return 0;
}
