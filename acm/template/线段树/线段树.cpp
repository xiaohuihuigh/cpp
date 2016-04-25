/*单点增加，区间求和*/
/*单点替换，区间最值*/
/*可以先初始化树，用update进行更新*/
#include <stdio.h>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,tr<<1|1

const int maxn = 5555;
int sum[maxn<<2];
void pushup(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1]};
}
void build(int l;int r;int rt){
    if(l==r){
        scanf("%d",&sum[rt]);
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int add,int l,int r,int rt){
    if(l == r){
        sum[rt]+= add;
        return;
    }
    int m = (l+r)>>1;
    if(p <= m)update(p,add,lson);
    else update(p,add,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L <= l&&r<=R){
        return sum[rt];
    }
    int m = (l+r)>>1;
    int ret = 0;
    if(L <= m)ret += query(L,R,lson);
    if(R>m)ret += query(L,R,rson);
    return ret;
}
/*成段更新，单点求值*/
 #include <stdio.h>
 # include<algorithm>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,tr<<1|1

const int maxn = 5555;
int sum[maxn<<2];
int col[maxn<<2];
void pushup(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1]};
}
void pushdown(int rt,int m){
    if(col[rt]){
        col[rt<<1] = col[rt<<1|1]=col[rt];
        sum[rt<<1] = (m - (m >> 1)) * col[rt];
        sum[rt<<1|1] = (m >> 1) * col[rt];
        col[rt] = 0;
    }
}
void build(int l;int r;int rt){
   col[rt] = 0;
   col[rt] = 1;
   if(l == r)return ;
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,int c,int l,int r,int rt){
    if(L <= l && r <= R){
        col[rt] = c;
        sum[rt] = c * (r-l+1);
        return ;
    }
    pushdown(rt,r-l+1);
    int m = (l+r)>>1;
    if(L <= m)update(L,R,c,lson);
    if(R > m)update(L,R,c,rson);
    pushup(rt);

   }
int main(){
    int T,n,m;
    scanf("%d",&T);
    for(int cas = 1;cas<=T;cas++){
        scanf("%d%d",&n,&m);
        build(1,n,1);
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",cas, sum[l]);
    }
    return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
const int maxn = 111111;
ll add[maxn<<2];
ll sum[maxn<<2];
void push_up(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void push_down(int rt,int m){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] +=add[rt];
        sum[rt<<1] += add[rt]*(m-(m>>1));
        sum[rt<<1|1] += add[rt]* (m>>1);
        add[rt] = 0;
    }
}
void build(int l,int r,int rt){
    add[rt] = 0;
    if(l == r){
        scanf("%lld",&sum[rt]);
        return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,int c,int l,int r,int rt){
    if(L <= l&& r <= R){
        add[rt] += c;
        sum[rt] += (ll)c* (r-l+1);
        return;
    }
    push_down(rt,r-l+1);
    int m = (l+r)>>1;
    if(L <= m)update(L,R,c,lson);
    if(m < R)update(L,R,c,rson);
    push_up(rt);
}
ll query(int L,int R,int l,int r,int rt){
    if(L <= l&&r <= R){
        return sum[rt];
    }
    push_down(rt,r-l+1);
    int m = (l+r)>>1;
    ll ret = 0;
    if(L<=m)ret += query(L,R,lson);
    if(m<R) ret += query(L,R,rson);
    return ret;
}
int main(){
    int N,Q;
    scanf("%d%d",&N,&Q);
    build(1,N,1);
    while(Q--){
        char op[2];
        int a,b,c;
        scanf("%s",op);
        if(op[0] == 'Q'){
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(a,b,1,N,1));
        }
        else{
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,N,1);
        }
    }
    return 0;
}
/*成段增长，区间求和*/

