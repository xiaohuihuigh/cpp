#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int v[maxn];
int dp[maxn];
int ln[maxn];
int main(){
	int n;
	while(cin>>n&&n){
		for(int i  = 0;i < n;i++){
			cin>>v[i];
		}
		memset(dp,0,sizeof(dp));
		dp[1] = v[0];
		int len = 1;
		for(int i = 1;i < n;i++){
			if(dp[len] < v[i]){ dp[++len] = v[i];
			ln[i] = len;}
			else{
				int p = upper_bound(dp+1,dp+len+1,v[i]) - dp;
				dp[p] = v[i];
				ln[i] = p;
			}
		}
		int s = dp[len];int t = 0;int sum = 0;int lenn = len;
		for(int i = 0;i<len;i++){
			for(int j = 0;j<n;j++){
				if(v[j]<s&&ln[j] == lenn){
					t = max(t,v[j]);
				}
			}
			sum+=t;lenn--;
		}
		cout<<sum<<endl;
	}
	return 0;
}


