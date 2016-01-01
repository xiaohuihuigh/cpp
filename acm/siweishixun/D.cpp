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

ll  maps[27][27];

void yanghui(){
	REP(i,27)REP(j,27)maps[i][j] = 0;
	 maps[1][1] = 1;
	 maps[2][1] = 1;
	 maps[2][2] = 1;
	 REP2(i,3,26)REP2(j,3,i)maps[i][j] = maps[i-1][j]+maps[i-1][j-1];
}
int main(){
	int n;int ca = 0;
	yanghui();
	while(cin>>n){
		cout<<"Case "<<++ca<<": n="<<n<<endl;
		REP2(i,1,n+1){if(i != 1)cout<<" ";cout<<maps[n+1][i];}
		cout<<endl;
	}
}











