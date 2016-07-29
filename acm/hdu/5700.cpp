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
const int maxn = 100005;
ll sum[maxn];
ll a[maxn];


struct node{
    int l,r;
}q[maxn];

int lb(int x){return x&(-x);}
template<typename X>
struct tree_arr{
    X bits[maxn];
    int n;
    void init(int s){n = s;for(int i = 0;i<=n;i++)bits[i] = 0;}
    void add(int x,X y){while(x<=n){bits[x]+=y;x+=lb(x);}}
    X query(int x){X s = 0;while(x>0){s+=bits[x];x-=lb(x);}return s;}
};
tree_arr<long long > tr;
int cmp(node x,node y){
    if(x.l == y.l)return x.r<y.r;
    return x.l<y.l;
}
int main(){
    int n,k,m;
    while(in3(n,k,m)!= EOF){
        sum[0] = 0;
        for(int i = 1;i<=n;i++){
            in(a[i]);
            sum[i]+=sum[i-1]+a[i];
        }
        tr.init(n);
        for(int i = 0;i<m;i++){
            in2(q[i].l,q[i].r);
        }
//        for(int i = 1;i<=n;i++){
//            cout<<tr.sum(i)<<endl;
//        }
        sort(q,q+m,cmp);
//        for(int i = 0;i<m;i++){
//            cout<<q[i].l<<" "<<q[i].r<<endl;
//        }
        int l1 = 1;
        ll ans = 0;
        for(int i = 0;i<m;i++){
            while(l1 == q[i].l){
                tr.add(q[i].l,1);tr.add(q[i].r+1,-1);
                i++;
            }
            i--;
            int l = l1, r = n;
            while(l<r){
                int mid = (l+r-1)/2+1;
                if(tr.query(mid)<=k) l = mid;
                else r = mid-1;
            }

            cout<<l<<endl;
            ans = max(ans,sum[l] - sum[l1-1]);
            l1++;
        }
        cout<<ans<<endl;


    }
}
