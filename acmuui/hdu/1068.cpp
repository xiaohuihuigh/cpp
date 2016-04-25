/*
最大独立集 = 顶点数 - 2*最大匹配数 + 最大匹配数
独立集指在该集合中的点两两之间没有边
至于后面的+最大匹配数，因为拿一半的点过来也是没有边的
*/
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

VI G[5550];
int match[10050];
bool used[10050];

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
    int n,k,knn;
    while(cin>>n){
             REP(i,5550)
                G[i].clear();
    //scanf("%d%d",&n,&m);
    for(int j = 0;j< n;j++){
        scanf("%d: (%d)",&k,&knn);

        int a,b;

        for(int i = 0;i< knn;i++){
            scanf("%d",&b);
            G[k].PB(b);
        }
    }
    /*int ans = 0;
    for(int i = 0;i< n;i++){
            CLR(used, 0);
        if(h(i))
            ans++;
    }*/
   // printf("%d\n",n-ans/2);
    cout<<n - hungary(n)<<endl;

    }
    return 0;

}
