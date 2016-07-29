//#include<bits/stdc++.h>
//using namespace std;
//#define ca(x) scanf("%d",&x)
//#define lson l,m,rt<<1
//#define rson m+1,r,rt<<1|1
//typedef long long ll;
//const int maxn = 100005;
//int sum[maxn<<2];
//int a[maxn];
//map<ll,ll>f[maxn];
//map<ll,ll>cnt;
//void pushup(int rt){
//    sum[rt] = __gcd(sum[rt<<1],sum[rt<<1|1]);
//}
//void build(int l,int r,int rt){
//    if(l==r){
//        sum[rt] = a[l];
//        return;
//    }
//    int m = (l+r)>>1;
//    build(lson);
//    build(rson);
//    pushup(rt);
//}
//ll query(int L,int R,int l,int r,int rt){
//    if(L <= l&&r<=R){
//        return sum[rt];
//    }
//    int m = (l+r)>>1;
//    ll ls  = 0;ll rs = 0;
//    if(L <= m)ls =query(L,R,lson);
//    if(R>m)rs =query(L,R,rson);
//    if(!ls)return rs;
//    if(!rs)return ls;
//    return __gcd(ls,rs);
//}
//int main(){
//    int T;ca(T);
//    int ca = 0;
//    while(T--){
//        ca++;
//        int n;ca(n);
//        for (int i = 1;i<=n;i++){
//        	ca(a[i]);
//        }
//        build(1,n,1);
//        int q;
//        ca(q);
//        cnt.clear();
//        for(int i = 0;i<=n;i++)f[i].clear();
//        cnt[a[1]] = 1;
//        f[1][a[1]] = 1;
//        for(int i = 2;i<=n;i++){
//            int s = a[i];
//            cnt[s]++,f[i][s] = 1;
//            for(map<ll,ll>::iterator it = f[i-1].begin();it!=f[i-1].end();it++){
//                ll tmp = __gcd(ll(s),it->first);
//                f[i][tmp] +=it->second;
//                cnt[tmp] +=it->second;
//
//            }
//        }
//
//        printf("Case #%d:\n",ca);
//        while(q--){
//            int x,y;
//            ca(x),ca(y);
//            ll ans = query(x,y,1,n,1);
//            printf("%lld %lld\n",ans,cnt[ans]);
//        }
//    }
//}
#include<bits/stdc++.h>
using namespace std;
#define ca(x) scanf("%d",&x)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int maxn = 100005;
int sum[maxn<<2];
int a[maxn];
map<ll,ll>f[maxn];
map<ll,ll>cnt;
void pushup(int rt){
    sum[rt] = __gcd(sum[rt<<1],sum[rt<<1|1]);
}
void build(int l,int r,int rt){
    if(l==r){
        scanf("%d",&sum[rt]);
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
ll query(int L,int R,int l,int r,int rt){
    if(L <= l&&r<=R){
        return sum[rt];
    }
    int m = (l+r)>>1;
    ll ls  = 0;ll rs = 0;
    if(L <= m)ls =query(L,R,lson);
    if(R>m)rs =query(L,R,rson);
    if(!ls)return rs;
    if(!rs)return ls;
    return __gcd(ls,rs);
}
int main(){
    int T;
    ca(T);
    int ca = 0;
    while(T--){
        ca++;
        int n;
        ca(n);
        build(1,n,1);
        int q;
        ca(q);
        cnt.clear();
        for(int i = 0;i<=n;i++)f[i].clear();
        cnt[query(1,1,1,n,1)] = 1;
        f[1][query(1,1,1,n,1)] = 1;
        for(int i = 2;i<=n;i++){
            int s = query(i,i,1,n,1);
            cnt[s]++,f[i][s] = 1;
            for(map<ll,ll>::iterator it = f[i-1].begin();it!=f[i-1].end();it++){
                ll tmp = __gcd(ll(s),it->first);
                f[i][tmp] +=it->second;
                cnt[tmp] +=it->second;

            }
        }

        printf("Case #%d:\n",ca);
        while(q--){
            int x,y;
            ca(x),ca(y);
            int ans = query(x,y,1,n,1);
            printf("%d %lld\n",ans,cnt[ans]);
        }
    }
}
