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
int yen = 1;
int a[11][11];
int num[11] ;
void dfs(int i,int j)
{
	if(i==10){
		REP2(i,1,9)
		{
			if(num[i] != 0)
			{
				yen = 0;
				break;
			}
		}
		return;
	}
	if(yen ==1){
		num[a[i][j]] = 0;
		dfs(i+1,j);
		dfs(i+1,j+1);
		num[a[i][j]] = 1;
	}
	
//	return;
}
int main()
{
	int n,ca = 0;
	cin>>n;
	while(n--)
	{
		memset(num,1,sizeof(num));
		REP(i,9){
		REP2(j,0,i)
		{
			cin>>a[i][j];

		}
		}
		dfs(0,0);
		printf("Case %d:\n",++ca);

		if(yen)
		cout<<"Possible"<<endl;
		else
		cout<<"Impossible"<<endl;
	}
	return 0;
}
/**/
