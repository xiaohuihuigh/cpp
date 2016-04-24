#include<bits/stdc++.h>
using namespace std;
int dp[5040][5040];
char a[5040];
char b[5040];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>a>>b;
		int la = strlen(a);
		int lb = strlen(b);
		for(int i = 0;i<la;i++)dp[i][0]=  0;
		for(int i = 0;i<lb;i++)dp[0][i]=  0;
		for(int i = 1;i<=la;i++){
			for (int j = 1;j<=lb;j++){
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1]+1;
				}
				else{
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		cout<<dp[la][lb]<<endl;
	}
}


