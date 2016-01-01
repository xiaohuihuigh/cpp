#include<iostream>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10000;
long long  v[maxn];
long long w[maxn];
long long dp[maxn];
int  main(){
	int T;
	cin>>T;
	while(T--){
		long long n,m;
		 cin>>n>>m;
		for(int i = 1;i<=n;i++){
			cin>>w[i];
		}
		for(int i = 1;i<=n;i++){
			cin>>v[i];
		}
		//memset(dp,-INF,sizeof(dp));
		memset(dp,0,sizeof(dp));
		dp[0] = 0;

		for(int i = 1;i<=n;i++){
			for(int j = m;j>=v[i];j--){
				if(dp[j]<=dp[j-v[i]]+w[i]){
					dp[j] = dp[j-v[i]]+w[i];
				}
			}
		}
		//for(int i = 0;i<=m;i++)
		cout<<dp[m]<<endl;

	}
}
