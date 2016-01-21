
/*成段增长，区间求和*/
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
        sum[rt<<1] += add[rt]*(m-m>>1);
        sum[rt<<1|1] += add[rt]* (m>>1);
        add[rt] = 0;
    }
}
void build(int l,int r,int rt){
    add[rt] = 0;
    if(l == r){
        scanf("%d",&sum[rt]);
        return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    push_up(rt);
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
