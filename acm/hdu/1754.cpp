#include <stdio.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,tr<<1
const int maxn = 5555;
int sum[maxn<<2];
void push_up(int rt){
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
void update(itn p,int add,int l,int r,int rt){
    if(l == r){
        sum[rt]+= add;
        return;
    }
    int m = (l+r)>>1;
    if(p <= m)update(p,add,lson);
    else update(p,add,rson);
    push_up(rt);
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
