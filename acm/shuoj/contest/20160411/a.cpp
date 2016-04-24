//#include<bits/stdc++.h>
//using namespace std;
//int val[35];
//int dp[150][36];
//
//int main(){
//	int T;
//	cin>>T;
//	int ca = 1;
//	while(T--){
//		int n,m;
//		cin>>n>>m;
//		memset(dp,0,sizeof(dp));
//		int maxn = 0;
//		for(int i = 0;i<n;i++){
//			cin>>val[i];
//			maxn = max(maxn,val[i]);
//			dp[val[i]][val[i]]= 1;
//		}
////		dp[0][0] = 1;
//		for(int i = 1;i<=m;i++){
//			for(int j = 1;j<=maxn;j++){
//				int yn  = 0;
//				for(int k = 0;k<n;k++){
//					if(i>=j&&val[k] == j){
//						dp[i][j] +=dp[i][j-1]+dp[i-j][j];
//						yn = 1;
//						break;
//					}
//				}
//				if(yn == 0)dp[i][j] =dp[i][j-1];
//
//			}
//		}
//		cout<<"Case #"<<ca++<<": ";
//		cout<<dp[m][maxn]<<endl;
//	}
//}
#include<bits/stdc++.h>
using namespace std;
int val[35];
int dp[36][150];

int main(){
	int T;
	cin>>T;
	int ca = 1;
	while(T--){
		int n,m;
		cin>>n>>m;
		memset(dp,0,sizeof(dp));
		int maxn = 0;
		for(int i = 0;i<n;i++){
			cin>>val[i];
		}
		for(int i = 0;i<n;i++)dp[i][0] = 1;
		for(int i= 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				dp[i][j] = 0;
				for(int k = 0;k<=j/val[i-1];k++){
					dp[i][j] +=dp[i - 1][j - val[i-1]*k];
				}
				//cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
			}
		}
		cout<<"Case #"<<ca++<<": ";
		cout<<dp[n][m]<<endl;
	}
}
