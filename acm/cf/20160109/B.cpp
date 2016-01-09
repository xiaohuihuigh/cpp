#include<bits/stdc++.h>
using namespace std;
const int maxn = 100050;
typedef long long ll;
vector<int>V[maxn];
int dp[maxn];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	memset(dp,0,sizeof(dp));
	dp[1] = 1;ll ans = 1;
	for(int i = 1;i<=n;i++){
		dp[i] = 1;
		for(int j = 0;j<V[i].size();j++){
			if(i>V[i][j]){
				dp[i] = max(dp[i],dp[V[i][j]]+1);
			}
		}
		int t  = V[i].size();
		//cout<<t<<" "<<dp[i]<<endl;
		ans = max(ans,1ll*dp[i]*t);
	}
	cout<<ans<<endl;


}
