#include<bits/stdc++.h>
using namespace std;
long long dp[66];
void dpp (){
	dp[1] =  3;
	dp[2] = 6;
	dp[3] = 6;
	for(int i = 4;i<62;i++){
		dp[i] = dp[i-1]+2*dp[i-2];
	}
}
int main(){
	int n;
	dpp();
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
}

