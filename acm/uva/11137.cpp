#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10005][23];

int main(){
	memset(dp,0,sizeof(dp));
	for(int i = 1;i<=22;i++)dp[0][i] = 1;
	for(int i = 1;i<=10000;i++){
		for(int j = 1;j<=22;j++){
			if(i>=j*j*j)
			dp[i][j] = dp[i][j-1]+dp[i-j*j*j][j];
			else dp[i][j] = dp[i][j-1];
		}
	}

	int n;
	while(cin>>n){
				cout<<dp[n][22]<<endl;
			}
		}
/*
完全背包版
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10005];

int main(){
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int j = 1;j<=22;j++){
	for(int i = j*j*j;i<=10000;i++){
		dp[i] = dp[i]+dp[i-j*j*j];
		}
	}

	int n;
	while(cin>>n){
				cout<<dp[n]<<endl;
			}
		}

*/


