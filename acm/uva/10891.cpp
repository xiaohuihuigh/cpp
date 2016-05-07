//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 110;
//int dp[maxn][maxn];
//int sum[maxn];
//bool vis[maxn][maxn];
//int dpp(int a,int b){
//	if(vis[a][b])return dp[a][b];
//	vis[a][b] = true;
//	int m = 0;
//	for(int k = a+1;k<=b;k++) m = min(m,dpp(k,b));
//	for(int k = a;k<b;k++) m = min(m,dpp(a,k));
//	dp[a][b] = sum[b] - sum[a-1]- m;
//	return dp[a][b];
//
//}
//int main(){
//	int n;
//	while(cin>>n&&n){
//		sum[0] = 0;
//		memset(vis,false,sizeof(vis));
//		for(int i = 1;i<=n;i++){
//			int a;
//			cin>>a;
//			sum[i] = sum[i-1]+a;
//		}
//		cout<<2*dpp(1,n) - sum[n]<<endl;
//	}
//}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int dp[maxn][maxn];
int sum[maxn];

int main(){
	int n;
	while(cin>>n&&n){
		sum[0] = 0;
		for(int i = 1;i<=n;i++){
			int a;
			cin>>a;
			sum[i]=  sum[i-1]+a;
			dp[i][i] = a;
		}
		for(int p = 1;p<n;p++){
			for(int i = 1,j = i+p;j<=n;i++,j++){
				int m = 0;
				for(int k = i;k<j;k++){
					m = min(dp[i][k],min(dp[k+1][j],m));
				}
				dp[i][j] = sum[j] - sum[i-1] - m;
			}
		}
		cout<<dp[1][n] - (sum[n] - dp[1][n])<<endl;
	}
}
