#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

char s[10][10];

ll dp[1000000][2];

int isp[21] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};

int main()
{
#ifdef LOCAL
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    int n,m;
    scanf("%d%d",&n,&m);

    int t = 1;
    REP(i,m) t *= 10;
    dp[0][0] = 1;
    REP(i,n) {
        scanf("%s", s[i]);
    }
    int v = 0;
    REP(i,n) {
        REP(j,m) {
            REP(k,t) if(dp[k][v]) {
                int first = k / (t/10);
                int last = k % 10;
                REP(add,10) if( (s[i][j] == '?' || s[i][j] == '0' + add) && (!i || isp[add+first]) && (!j || isp[add+last])){
                    int kk = k - first * (t/10);
                    kk = kk * 10 + add;
                    dp[kk][v^1] += dp[k][v];
                }
                dp[k][v] = 0;
            }
            v = v^1;
        }
    }
    ll res = 0;
    REP(i,t) res += dp[i][v];
    cout<<res<<endl;
    return 0;
}
