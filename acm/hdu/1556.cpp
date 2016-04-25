#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  printf("%d\n",x)
const int maxn = 100000;
int sum[maxn<<2];
int add[maxn<<2];
void pushup(int rt){
	sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int rt,int len){
	if(add[rt]){
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		sum[rt<<1]+=add[rt]*(len - (len>>1));
		sum[rt<<1|1]+=add[rt]*(len>>1);
		add[rt] = 0;
	}
}
void build(int l,int r,int rt){
	add[rt] =0;
	if(l>r)return ;
	if(l == r){
		sum[rt] = 0;
		return ;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R){
		add[rt] += 1;
		sum[rt]+= (r-l+1);
		return;
	}
	pushdown(rt,r-l+1);
	int m = (l+r)>>1;
	if(L<=m)update(L,R,lson);
	if(m<R)update(L,R,rson);
	pushup(rt);
}
void query(int l,int r,int rt){
    if(l == r){
        return;
    }
    pushdown(rt,r-l+1);
    int m = (l+r)>>1;
    query(lson);
    query(rson);
}
ll query(int t,int l,int r,int rt){
    if(l == r&&l == t){
        return sum[rt];
    }
    int m = (l+r)>>1;
    ll ret = 0;
    if(t<=m)ret+=query(t,lson);
    else ret+=query(t,rson);
    return ret;
}
int main(){
	int n;
	while(~in(n)&&n){
	build(1,n,1);
	for(int i = 1;i<=n;i++){
		int a,b;
		in2(a,b);
		update(a,b,1,n,1);
	}
	query(1,n,1);
	for(int i = 1;i<=n;i++){
	if(i!=1)printf(" ");
	printf("%I64d",query(i,1,n,1));
		///cout<<query(i,1,n,1)<<endl;
	}
	printf("\n");
	}
}
/*
const int maxn = 100000;
int sum[maxn<<2];
int add[maxn<<2];
void pushup(int rt){
	sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int rt,int len){
	if(add[rt]){
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		sum[rt<<1]+=add[rt]*(len - (len>>1));
		sum[rt<<1|1]+=add[rt]*(len>>1);
		add[rt] = 0;
	}
}
void build(int l,int r,int rt){
	add[rt] =0;
	if(l>r)return ;
	if(l == r){
		sum[rt] = 0;
		return ;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R){
		add[rt] += 1;
		sum[rt]+= (r-l+1);
		return;
	}
	pushdown(rt,r-l+1);
	int m = (l+r)>>1;
	if(L<=m)update(L,R,lson);
	if(m<R)update(L,R,rson);
	pushup(rt);
}
long long query(int t,int l,int r,int rt){
    if(l == r&&l == t){
        return sum[rt];
    }
    pushdown(rt,r-l+1);
    int m = (l+r)>>1;
    long long ret = 0;
    if(t<=m)ret += query(t,lson);
    if(m<t) ret += query(t,rson);
    return ret;
}
int main(){
	int n;
	while(~in(n)&&n){
	build(1,n,1);
	for(int i = 1;i<=n;i++){
		int a,b;
		in2(a,b);
		update(a,b,1,n,1);
	}
	for(int i = 1;i<=n;i++){
	if(i!=1)printf(" ");
	printf("%I64d",query(i,1,n,1));
		///cout<<query(i,1,n,1)<<endl;
	}
	printf("\n");
	}
}
*/
