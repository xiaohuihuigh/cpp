#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int maps[25][15];
int dp[25][15];
int abs(int x){
    if(x>0)return x;
    return -x;
}

int main(){
	int N,K;
	while(cin>>N>>K){
		for(int i = 1;i<= N;i++){
			for(int j = 1;j<=K;j++ ){
				cin>>maps[i][j];
			}
		}
		memset(dp,INF,sizeof(dp));
		for(int i = 1;i<=K;i++)dp[1][i] = 0;
		for(int i = 2;i<=N;i++){
			for(int j = 1;j<=K;j++){
				for(int k = 1;k<=K;k++){
                    if(dp[i][j]>dp[i-1][k]+abs(maps[i][j] - maps[i-1][k]))
                        dp[i][j] = dp[i-1][k]+abs(maps[i][j] - maps[i-1][k]);
				}
			}
		}
		int ans = INF;
		for(int i = 1;i<=K;i++){
                if(ans>dp[N][i])
			ans =dp[N][i];
		}
		cout<<ans<<endl;
	}
	return 0;
}



