#include <bits/stdc++.h>
#include<iostream>
using namespace std;

#define lson l,m,rt<<1
#define ll long long
#define rson m+1,r,rt<<1|1
int w[5][5];

const int mod  =777777777;
int dp[300010][4][4];
void pushup(int rt){
	for(int i = 0;i<3;i++)
	for(int j = 0;j<3;j++){
		dp[rt][i][j] = 0;
		for(int k = 0;k<3;k++)
		for(int l = 0;l<3;l++){
			if(!w[k][l])continue;
			dp[rt][i][j] = (dp[rt][i][j] +1ll*dp[rt<<1][i][k]*dp[rt<<1|1][l][j])%mod;
		}
	}
}
void build(int l,int r,int rt){
	if(l>r)return ;
    if(l==r){
	for(int i = 0;i<3;i++)
	for(int j = 0;j<3;j++)dp[rt][i][j] = 0;
	for(int i = 0;i<3;i++)dp[rt][i][i] = 1;

        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int add,int l,int r,int rt){
if(l>r)return ;
    if(l == r){
       for(int i = 0;i<3;i++)
	for(int j = 0;j<3;j++)dp[rt][i][j] = 0;
	if(!add){for(int j = 0;j<3;j++)dp[rt][j][j] = 1;}
	else dp[rt][add-1][add-1] = 1;
        return;
    }
    int m = (l+r)>>1;
    if(p <= m)update(p,add,lson);
    else update(p,add,rson);
    pushup(rt);
}

int main(){
    int T,n,m;
    ios::sync_with_stdio(false);
        cin>>n>>m;
	//build(1,n,1);
        for(int i = 0;i<3;i++)
	for(int j = 0;j<3;j++){cin>>w[i][j];}
	build(1,n,1);
	while(m--){
		int a,b;
		cin>>a>>b;
		update(a,b,1,n,1);
		int  ans = 0;
		for(int i = 0;i<3;i++)
		for(int j = 0;j<3;j++)
		ans = (ans+1ll *dp[1][i][j])%mod;
		cout<<ans<<endl;
	}
    return 0;
}/*


#include<bits/stdc++.h>
using namespace std;
#define rep(X,N) for(int X = 0;X<N;X++)
typedef long long LL;
int ok[5][5];
int dp[300010][3][3];
int n ;
const int mod = 777777777;
void push_up(int r){
	rep(i,3)
	rep(j,3){
		dp[r][i][j] = 0;
		rep(k,3)
		rep(l,3){
			if(!ok[k][l])continue;
			dp[r][i][j] = (dp[r][i][j]+1LL*dp[r<<1][i][k]*dp[r<<1|1][l][j])%mod;
		}
	}
}
void build(int l = 1,int r = n,int cur = 1){
	if(l>r)return;
	if(l == r){
		rep(i,3)
		rep(j,3)dp[cur][i][j] = 0;
		rep(i,3)dp[cur][i][i] = 1;
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
	push_up(cur);
}
int v,t;
void update(int l = 1,int r = n,int cur = 1){
	if(r<l)return;
	if(l ==r ){
		rep(i,3)
		rep(j,3)dp[cur][i][j]= 0;
		if(!t){
			rep(i,3)dp[cur][i][i] = 1;
		}
		else dp[cur][t-1][t-1] =1;
		return;
	}
	int mid = (l+r)>>1;
	if(v <=mid)update(l,mid,cur<<1);
	else update(mid+1,r,cur<<1|1);
	push_up(cur);
}

int main(){
	ios::sync_with_stdio(false);
	int m;
	cin>>n>>m;
	rep(i,3)
	rep(j,3)cin>>ok[i][j];
	build();
	int ans = 0;
	while(m--){
		cin>>v>>t;
		update();
		ans = 0;
		rep(i,3)
		rep(j,3){
			ans = (ans+1ll*dp[1][i][j])%mod;
		}
		cout<<ans<<endl;
	}
}







*/



