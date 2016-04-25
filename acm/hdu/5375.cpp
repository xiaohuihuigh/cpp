#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 200005;
int val[maxn];
int dp[maxn][3];
const int INF = 0x3f3f3f3f;
int main(){
	//std::ios::sync_with_stdio(0);
	int T;
	scanf("%d",&T);
	int ca = 0;
	while (T--){
		string a;
		cin>>a;
		int n = a.length();
		for(int i = 0;i<n;i++){
			scanf("%d",&val[i]);
		}
		dp[0][0] = dp[0][1] = -INF;
		if(a[0] == '0'||a[0] == '?'){
			dp[0][0] = 0;
		}
		if(a[0]=='1'||a[0] == '?'){
			dp[0][1] = val[0];
		}
		for(int i = 1;i<n;i++){
			dp[i][0] = dp[i][1] = -INF;
			if(a[i] == '0'||a[i] == '?'){
				dp[i][0] = max(dp[i-1][0],dp[i-1][1]+val[i]);
			//	cout<<dp[i][0]<<endl;
			}
			if(a[i]=='1'||a[i] == '?'){
				dp[i][1] = max(dp[i-1][1],dp[i-1][0]+val[i]);
			//	cout<<dp[i][1]<<endl;
			}
		}
		//cout<<dp[n-1][0]<<" "<<dp[n-1][1];
		cout<<"Case #"<<++ca<<": ";
		cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
	}
	return 0;
}



