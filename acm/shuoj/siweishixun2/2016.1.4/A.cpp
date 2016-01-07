#include<bits/stdc++.h>
using namespace std;
long long dp[10000];
void dpp(int n){
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2;i<=47;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
}
int main(){
	int n;
	dpp(47);
	while(cin>>n&&n!=-1){
		int yn  =0;
		for(int i = 0;i<=47;i++){
			if(dp[i] == n){
				cout<<i<<endl;
				yn = 1;
				break;
			}
		}
		if(yn == 0)cout<<"Not a Fibonacci number."<<endl;
	}
}
