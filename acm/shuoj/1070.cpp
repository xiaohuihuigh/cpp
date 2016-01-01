#include<iostream>
using namespace std;

long long dp[35];

void dps(){
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4;i<=35;i++){
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	}
}
int main(){
	int n;
	dps();
	while(cin>>n&&n){
		cout<<dp[n]<<endl;
	}
	return 0;
}
