//
///*成段增长，区间求和*/
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//#define lson l,m,rt<<1
//#define rson m+1,r,rt<<1|1
//#define ll long long
//const int maxn = 111111;
//ll add[maxn<<2];
//ll sum[maxn<<2];
//void push_up(int rt){
//    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
//}
//void push_down(int rt,int m){
//    if(add[rt]){
//        add[rt<<1] += add[rt];
//        add[rt<<1|1] +=add[rt];
//        sum[rt<<1] += add[rt]*(m-(m>>1));
//        sum[rt<<1|1] += add[rt]* (m>>1);
//        add[rt] = 0;
//    }
//}
//void build(int l,int r,int rt){
//    add[rt] = 0;
//    if(l == r){
//        scanf("%I64d",&sum[rt]);
//        return ;
//    }
//    int m = (l+r)>>1;
//    build(lson);
//    build(rson);
//    push_up(rt);
//}
//void update(int L,int R,int c,int l,int r,int rt){
//    if(L <= l&& r <= R){
//        add[rt] += c;
//        sum[rt] += (ll)c* (r-l+1);
//        return;
//    }
//    push_down(rt,r-l+1);
//    int m = (l+r)>>1;
//    if(L <= m)update(L,R,c,lson);
//    if(m < R)update(L,R,c,rson);
//    push_up(rt);
//}
//ll query(int L,int R,int l,int r,int rt){
//    if(L <= l&&r <= R){
//        return sum[rt];
//    }
//    push_down(rt,r-l+1);
//    int m = (l+r)>>1;
//    ll ret = 0;
//    if(L<=m)ret += query(L,R,lson);
//    if(m<R) ret += query(L,R,rson);
////    else{
////        ret+=query(L,m,lson);
////        ret+=query(m+1,R,rson);
////    }
//    return ret;
//}
//int main(){
//    int N,Q;
//    scanf("%d%d",&N,&Q);
//    build(1,N,1);
//    while(Q--){
//        char op[2];
//        int a,b,c;
//        scanf("%s",op);
//        if(op[0] == 'Q'){
//            scanf("%d%d",&a,&b);
//            printf("%I64d\n",query(a,b,1,N,1));
//        }
//        else{
//            scanf("%d%d%d",&a,&b,&c);
//            update(a,b,c,1,N,1);
//        }
//    }
//    return 0;
//}
/*
树状数组区间更新，区间求和
利用两个树状数组进行实现
原理

先讲：通过树状数组的区间更新，单点查询我们知道
对一个点i的更新值为sum(c[1...i])+a[i] a[]为初始数据，c[]为树状数组的值
那么对于区间[l,r]
则为：SUM = sum[a[l...r]]+sum[sum(c[1...l])...sum(c[1...r])]
                   A     +   B
A部分用前缀和
B部分
B = c[1]+c[1...2]+c[1...3]+...+c[1...r] - (c[1]+c[1...2]+c[1...3]+...+c[1...r])
                C                       -          D
C 和D一个形式
C = r*c[1]+(r-1)*c[2]+...+c[r]
  = (r+1)*sum(c[1...r]) - (1*c[1]+2*c[2]+...＋ｒ*c[r])
  = (r+1)*sum(c[1...r]) - sum(i*c[1..r])
所以
SUM = sum[a[1...r]] - sum[a[1...l]]+(r+1)*sum(c[1...r]) - sum(i*c[1..r]) - ((l+1)*sum(c[1...l]) - sum(i*c[1..l]))
用前缀和处理a[]用树状数组处理c[]和i*c[]两个数组
*/
#include<cstdio>
#include<algorithm>
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
int lb(int i){return (-i)&i;}
template<typename X>
struct tree_arr{
    X bits[maxn];
    int n;
    void init(int s){n = s;rep2(i,1,s)bits[i] = 0;}
    void add(int i,X y){while(i<=n){bits[i]+=y;i+=lb(i);}}
    X query(int i){X s = 0;while(i>0){s+=bits[i];i-=lb(i);}return s;}
};
tree_arr<ll> d,di;
ll sum[maxn];
int main(){
    int n,q;
    while(in2(n,q)!= EOF){
        d.init(n);
        di.init(n);
        rep(i,n+1)sum[i] = 0;
        rep2(i,1,n){
            ll a;scanf("%I64d",&a);
            sum[i]+=sum[i-1]+a;
        }
        while(q--){
            char op[20];
            int x,y,z;
            scanf("%s",op);
            if(op[0] == 'Q'){
                in2(x,y);
                ll ans = 0;
                ans+=sum[y] - sum[x-1];
                ans+=(y+1)*d.query(y) - x*d.query(x-1);
                ans-=di.query(y) - di.query(x-1);
                printf("%I64d\n",ans);
            }
            else{
                in3(x,y,z);
                d.add(x,z);d.add(y+1,-z);
                di.add(x,x*z);di.add(y+1,(y+1)*(-z));
            }
        }
    }

}

