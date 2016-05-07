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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
//const int MAXN = 10010;
//#define INF 0x3FFFFFFF

int maps[101][101];
int main(){
	int n,m,ca = 0;
	while(cin>>m>>n){
		ca++;
		REP(i,m)REP(j,n)cin>>maps[i][j];
		if(ca != 1)cout<<endl;
		REP(i,n){REP(j,m){if(j != 0)cout<<" ";cout<<maps[j][i];}cout<<endl;}

	}
	return 0;
}






























