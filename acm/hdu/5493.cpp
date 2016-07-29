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
int ans[maxn];
int lb(int i){return (-i)&i;}
template<typename X>
struct tree_arr{
    X bits[maxn];
    int n;
    void init(int s){n = s;rep2(i,1,s)bits[i] = 0;}
    void add(int i,X y){while(i<=n){bits[i]+=y;i+=lb(i);}}
    X query(int i){X s = 0;while(i>0){s+=bits[i];i-=lb(i);}return s;}
};
tree_arr<int> rt;
int n;
struct node{
    int h,k;
}p[maxn];
int cmp(node a,node b){
    return a.h<b.h;
}

int query(int x,int modo){
    int k = p[x].k;
    if(modo == 1){
        int l = 0,r = n;
        while(l<r){
            int mid = (l+r-1)/2+1;
            if(rt.query(mid)<=k) l = mid;
            else r = mid-1;
        }
//        cout<<l<<endl;
        if(l+1 > n)return INF;
        return l+1;
    }
    else{
        k = n - x - k;
        if(k<0)return INF;
        int l = 0,r = n;
        while(l<r){
            int mid = (l+r-1)/2+1;
            if(rt.query(mid)<=k) l = mid;
            else r = mid-1;
        }
//        cout<<l<<endl;
        if(l+1 > n)return INF;
        return l+1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    int ca = 0;
//    cin>>T;
    in(T);
    while(T--){
        ca++;
//        cin>>n;
        in(n);
        rt.init(n);
        rep2(i,1,n){
            rt.add(i,1);
//            cin>>p[i].h>>p[i].k;
            in2(p[i].h,p[i].k);
        }
//        rep2(i,1,n){cout<<rt.query(i)<<endl;}
        sort(p+1,p+n+1,cmp);
        int yn = 1;
        rep2(i,1,n){
            int p1 = query(i,1);
            int p2 = query(i,-1);
//            cout<<i<<" "<<p1<<":"<<p2<<endl;
            if(p1>p2)swap(p1,p2);
            if(p1 == INF){yn = 0;break;}
            rt.add(p1,-1);
            ans[p1] = p[i].h;
        }
//        cout<<"Case #"<<ca<<": ";
        printf("Case #%d: ",ca);
        if(yn){
            rep2(i,1,n){
//                cout<<ans[i];i != n?cout<<" ":cout<<endl;
                printf("%d",ans[i]);
                i != n?printf(" "):printf("\n");
            }

        }
        else printf("impossible\n");
    }
}

