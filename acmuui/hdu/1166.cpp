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
const int maxn = 55555;
int sum[maxn<<2];
void PushUP(int rt) {
sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l,int r,int rt) {
if (l == r) {
       cin>>sum[rt];

return ;
}
int m = (l + r) >> 1;
build(lson);
build(rson);
PushUP(rt);
}
void update(int p,int add,int l,int r,int rt) {
if (l == r) {
sum[rt] += add;
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


int main(){
	std::ios::sync_with_stdio(0);
	int T;//cin>>T;
	int ca = 0;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		//cin>>n;
		cout<<"Case "<<++ca<<":"<<endl;
		build(1,n,1);

		string s;
		int x,y;
		while(cin>>s){
		    if(s[0] == 'E')break;
                cin>>x>>y;
			if(s[0] == 'Q'){
			//	cin>>x>>y;
				cout<<query(x,y,1,n,1)<<endl;
			}
			if(s[0] == 'A'){
				update(x,y,1,n,1);
			}
			if(s[0] == 'S'){
				update(x,-y,1,n,1);
			}
		}
	}

	return 0;










//#ifdef LOCAL
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//#endif


//printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);

}
