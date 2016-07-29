///*Ïß¶ÎÊ÷*/
//#include <iostream>
//#include <sstream>
//#include <ios>
//#include <iomanip>
//#include <functional>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <list>
//#include <queue>
//#include <deque>
//#include <stack>
//#include <set>
//#include <map>
//#include <cstdio>
//#include <cstdlib>
//#include <cmath>
//#include <cstring>
//#include <climits>
//#include <cctype>
//using namespace std;
//#define XINF INT_MAX
//#define INF 0x3FFFFFFF
//#define MP(X,Y) make_pair(X,Y)
//#define PB(X) push_back(X)
//#define REP(X,N) for(int X=0;X<N;X++)
//#define REP2(X,L,R) for(int X=L;X<=R;X++)
//#define DEP(X,R,L) for(int X=R;X>=L;X--)
//#define CLR(A,X) memset(A,X,sizeof(A))
//#define IT iterator
//#define lson l,m,((rt)<<1)
//#define rson m+1,r,((rt)<<1|1)
//#define ls(t) ((t)<<1)
//#define rs(t) ((t)<<1|1)
//#define in(x) scanf("%d",&x)
//#define in2(x,y) scanf("%d%d",&x,&y)
//#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
//#define out1(x)  printf("%d\n",x)
//
//typedef long long ll;
//typedef pair<int,int> PII;
//typedef vector<PII> VII;
//typedef vector<int> VI;
////const int maxn = 100010;
//const int maxn = 200001;
//int sum[maxn<<2];
//void PushUP(int rt) {
//    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
//}
//void build(int l,int r,int rt) {
//    sum[rt] = 0;
//if (l == r) {
//return ;
//}
//int m = (l + r) >> 1;
//build(lson);
//build(rson);
//}
//void update(int p,int add,int l,int r,int rt) {
//if (l == r) {
//sum[rt]++;
//return ;
//}
//int m = (l + r) >> 1;
//if (p <= m) update(p , add , lson);
//else update(p , add , rson);
//PushUP(rt);
//}
//int query(int L,int R,int l,int r,int rt) {
//if (L <= l && r <= R) {
//return sum[rt];
//}
//int m = (l + r) >> 1;
//int ret = 0;
//if (L <= m) ret += query(L , R , lson);
//if (R > m) ret += query(L , R , rson);
//return ret;
//}
//
//int a[maxn];
//int main(){
//	std::ios::sync_with_stdio(0);
//	int n;
//	cin>>n;
//	int ans = 0;
//	build(1,n,1);
//	REP(i,n){
//        cin>>a[i];
//        a[i]++;
//        ans+= query(a[i],n,1,n,1);
//        cout<<ans;
//        update(a[i],a[i],1,n,1);
//	}
//    int ret = ans;
//    for (int i = 0 ; i < n ; i ++) {
//        ans += n - a[i] - a[i] - 1;
//        ret = min(ret , ans);
//    }
//cout<<ret<<endl;//printf("%d\n",ret);
//
//	return 0;
//
////#ifdef LOCAL
////freopen("input.txt","r",stdin);
////freopen("output.txt","w",stdout);
////#endif
//
//
////printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);
//
//}
/*Ê÷×´Êý×é*/

#include<bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define it iterator
#define lson l,m,((rt)<<1)
#define rson m+1,r,((rt)<<1|1)
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  printf("%d\n",x)
typedef long long ll;
const int maxn = 5005;
int a[maxn];
int b[maxn];
int lb(int x){return x&(-x);}
template<typename X>
struct tree_arr{
    X bits[maxn];
    int n;
    void init(int s){n = s;for(int i = 0;i<=n;i++)bits[i] = 0;}
    void add(int x,X y){while(x<=n){bits[x]+=y;x+=lb(x);}}
    X sum(int x){X s = 0;while(x>0){s+=bits[x];x-=lb(x);}return s;}
};
tree_arr<long long > tr;

int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        tr.init(n);
        for(int i = 1;i<=n;i++){cin>>a[i];}
        long long s = 0;
        for(int i = n;i>0;i--){
            s+=tr.sum(a[i]+1);
            tr.add(a[i]+1,1);
        }
//        cout<<s<<endl;
        ll ans = s;
        for(int i = 1;i<n;i++){
            s = s + n - 2*a[i]-1;
//            cout<<s<<endl;
            ans = min(ans,s);
        }
        cout<<ans<<endl;
    }
}

