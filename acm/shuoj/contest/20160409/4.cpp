#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;

int w[maxn];
int t[maxn];
int c[maxn];
int id[maxn];
int ti[maxn];
int dp[maxn][maxn];
bool cmp(int x,int y){
	return t[x]<t[y];
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m,s;
		cin>>n>>m>>s;
		for(int i = 0;i<m;i++){
			cin>>w[i]>>t[i]>>c[i];
			id[i] = i;
		}
		memset(dp,inf,sizeof(dp));
		for(int i = 0;i<=n;i++)ti[i] = m+1;
		sort(id,id+m,cmp);
		int as = 1;
		for(int i = 0;i<m;i++){
			if(t[id[i]] > as){ti[as] = ti[as-1];as++;}
			if(t[id[i]] == as){ti[as] = i;as++;}
		}
		for(int i = 0;i<=s;i++)
		for(int j = 0;j<m;j++)
		if(i>=w[id[j]])
		dp[1][i] = min(dp[1][i-1],min(c[id[j]],dp[1][i]));
		else dp[1][i] = min(dp[1][i-1],dp[1][i]);
		//for(int i = 1;i<=m;i++)cout<<ti[i]<<endl;
		for(int i = 1;i<=n;i++){
		for(int k = 0;k<=s;k++)
			for(int j =ti[i] ;j<m;j++){
			if(k>w[id[j]])
				dp[i][k] = min(dp[i][k-1],min(dp[i][k],dp[i-1][k-w[id[j]]]+c[id[j]]));
			else dp[i][k] = min(dp[i][k-1],dp[i][k]);
			}
		}
		if(dp[n][s] == inf)cout<<-1<<endl;
		else
		cout<<dp[n][s]<<endl;
	}
}
