/*#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
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
		sum[rt<<1]+=add[rt]*(len - len>>1);
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
	while(cin>>n){
	build(1,n,1);
	for(int i = 1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		update(a,b,1,n,1);
	}
	for(int i = 1;i<=n;i++){
		cout<<query(i,1,n,1)<<endl;
	}
	}
}
*/

/*成段增长，区间求和*/
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
const int maxn = 100100;
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
        scanf("%lld",&sum[rt]);
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
	if(L<=l && r<=R){
		return sum[rt];
	}
    push_down(rt,r-l+1);
    int m = (l+r)>>1;
   ll ret  =0;
	if(L<=m)ret+=query(L,R,lson);
	if(m<R)ret+=query(L,R,rson);
    return ret;
}/*
int main(){
    int N,Q;
    while(~scanf("%d",&N)){
    Q = N;
    build(1,N,1);
    while(Q--){
        int a,b,c;
            scanf("%d%d",&a,&b);
            update(a,b,1,1,N,1);
             //for(int i = 1;i<=N;i++)
        //printf("%lld\n",query(i,1,N,1));
        query(1,N,1);
	for(int i = 1;i<=(N<<1)-1;i++)
        printf("%lld\n",sum[i]);
        query(1,N,1);
        cout<<"aesrghaser"<<endl;
        for(int i = 1;i<=(N<<1)-1;i++)
        printf("%lld\n",sum[i]);
        }

    }
    return 0;
}*/
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
