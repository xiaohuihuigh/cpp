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
#define lson l,m,((rt)<<1)
#define rson m+1,r,((rt)<<1|1)
#define ls(t) ((t)<<1)
#define rs(t) ((t)<<1|1)
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  printf("%d\n",x)

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
//const int maxn = 100010;
const int maxn = 200001;
int sum[maxn<<2];
void PushUP(int rt) {
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt) {
    sum[rt] = 0;
if (l == r) {
return ;
}
int m = (l + r) >> 1;
build(lson);
build(rson);
}
void update(int p,int add,int l,int r,int rt) {
if (l == r) {
sum[rt]++;
return ;
}
int m = (l + r) >> 1;
if (p <= m) update(p , add , lson);
else update(p , add , rson);
PushUP(rt);
}
int query(int L,int R,int l,int r,int rt) {
if (L <= l && r <= R) {
return sum[rt];
}
int m = (l + r) >> 1;
int ret = 0;
if (L <= m) ret += query(L , R , lson);
if (R > m) ret += query(L , R , rson);
return ret;
}

int a[maxn];
int main(){
	std::ios::sync_with_stdio(0);
	int n;
	cin>>n;
	int ans = 0;
	build(1,n,1);
	REP(i,n){
        cin>>a[i];
        a[i]++;
       ans+= query(a[i],n,1,n,1);
      cout<<ans;
        //REP(i,n) cout<<sum[i]<<endl;
        update(a[i],a[i],1,n,1);
	}
    int ret = ans;
    for (int i = 0 ; i < n ; i ++) {
        ans += n - a[i] - a[i] - 1;
        ret = min(ret , ans);
    }
cout<<ret<<endl;//printf("%d\n",ret);

	return 0;

//#ifdef LOCAL
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//#endif


//printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);

}
