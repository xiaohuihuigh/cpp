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
const int maxn = 1005;
int lb(int i){return (-i)&i;}
template<typename X>
struct tree_mul_arr{
    struct tree_arr{
        X bits[maxn];
        int n;
        void init(int s){n = s;rep2(i,1,s)bits[i] = 0;}
        void add(int i,X y){while(i<=n){bits[i]+=y;i+=lb(i);}}
        X query(int i){X s = 0;while(i>0){s+=bits[i];i-=lb(i);}return s;}
    } bits[maxn];
    int n;
    void init(int x,int y){
        n = x;
        rep2(i,1,x){
            bits[i].init(y);
        }
    }
    void add(int i,int j,X z){
        while(i<=n){
            bits[i].add(j,z);
            i+=lb(i);
        }
    }
    X query(int i,int j){
        X s = 0;
        while(i>0){
            s+=bits[i].query(j);
            i-=lb(i);
        }
        return s;
    }
};
tree_mul_arr<ll> tr;
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        tr.init(n,m);
        rep2(i,1,n){
            rep2(j,1,m){
                int t;
                cin>>t;
                tr.add(i,j,t);
            }
        }
//        rep2(i,1,n){
//        rep2(j,1,m){
//            cout<<tr.bits[i].bits[j]<<" ";
//        }cout<<endl;}
        ll ans = 0;
        rep2(i,x,n){
            rep2(j,y,m){
                ll sum = tr.query(i,j) - tr.query(i,j-y)-tr.query(i-x,j)+tr.query(i-x,j-y);
//                cout<<i<<" "<<j<<" "<<sum<<endl;
                ans = max(ans,sum);
            }
        }
        cout<<ans<<endl;
    }
}
