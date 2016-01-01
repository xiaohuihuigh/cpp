/*最大连通等于等于课程数为yes   Hungary*/

#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

VI G[555];
int match[1005];
bool used[1005];

bool h(int u) {
	used[u] = 1;
	REP(i,G[u].size()) {
		int v = G[u][i], w = match[v];
		if(w < 0 || ! used[w] && h(w)) {
			match[v] = u;
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int hungary(int n) {
	int res = 0;
	CLR(match, -1);
	REP(v, n) {
		if(match[v] < 0) {
			CLR(used, 0);
			if(h(v)) res ++;
		}
		//cout<<res<<" "<<v<<endl;
	}
	return res;
}
int main (){
    int T,n,m,num,a,b;
    while(cin>>n>>m){
        REP(i,555)
            G[i].clear();

        REP(i,m){
            cin>>a>>b;
            a--;b -- ;
            G[a].PB(b);
            }
        int ans = hungary(n);
        if(n == ans)
        cout<<"NO"<<endl;
        else cout<<n - ans<<endl;
    }
    return 0;

}
