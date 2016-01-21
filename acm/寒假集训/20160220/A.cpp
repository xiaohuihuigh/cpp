#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 5000;
typedef long long ll;
ll dp[maxn][5];
int main(){
	int T;
	cin>>T;
	int ca = 0;
	while(T--){
		int N,L;
		cin>>N>>L;
		L*=2;
		memset(dp,0,sizeof(dp));
		dp[0][0] = 0;
		 ll ans1 = -1;
		for(int i = 0;i<N;i++){
		int a,v;
			cin>>a>>v;
			a*=2;
			ans1 = max(ans1,(ll)v);
			for(int j = L;j>=a/2;j--){
			//cout<<"er"<<i<<endl;

				if(j>=a/2){
					dp[j][1] = max(dp[j-a/2][0]+v,dp[j][1]);
					dp[j][2] = max(dp[j-a/2][1]+v,dp[j][2]);
				}
				if(j>=a){
					dp[j][0] = max(dp[j-a][0]+v,dp[j][0]);
					dp[j][1] = max(dp[j-a][1]+v,dp[j][1]);
					dp[j][2] = max(dp[j-a][2]+v,dp[j][2]);
				}//cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
			}
		}
			ll ans = 0;
		for(int i = 1;i<=L;i++){
			//cout<<"ii"<<i<<endl;
			ans = max(ans,dp[i][0]);//cout<<ans<<endl;
			ans = max(ans,dp[i][1]);//cout<<ans<<endl;
			ans = max(ans,dp[i][2]);//cout<<ans<<endl;
		}
		cout<<"Case #"<<++ca<<": ";
		cout<<max(ans1,ans)<<endl;
	}
}/*
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 5000;
typedef long long ll;
ll dp[maxn][5];
ll f[maxn][5];
int main(){
	int T;
	cin>>T;
	int ca = 0;
	while(T--){
		int N,L;
		cin>>N>>L;
		L*=2;
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		dp[0][0] = 0;
		 ll ans1 = -1;
		for(int i = 0;i<N;i++){
		int a,v;
			cin>>a>>v;
			for(int j=0;j<=L;j++){
			    f[j][0]=dp[j][0];
			    f[j][1]=dp[j][1];
			    f[j][2]=dp[j][2];
			}
			a*=2;
			ans1 = max(ans1,(ll)v);
			for(int j = 0;j<=L;j++){
			//cout<<"er"<<i<<endl;
			if(j+a<=L){

				dp[j+a][0]=max(dp[j+a][0],f[j][0]+v);
				dp[j+a][1]=max(dp[j+a][1],f[j][1]+v);
				dp[j+a][2]=max(dp[j+a][2],f[j][2]+v);
			}
			if(j+(a/2)<=L){
				dp[j+(a/2)][1]=max(dp[j+(a/2)][1],f[j][0]+v);
				dp[j+(a/2)][2]=max(dp[j+(a/2)][2],f[j][1]+v);
			}
			}*/
			/***********/
				/*if(j>=a){
					dp[j][0] = max(dp[j-a][0]+v,dp[j][0]);
					dp[j][1] = max(dp[j-a/2][0]+v,max(dp[j-a][1]+v,dp[j][1]));
					dp[j][2] = max(dp[j-a/2][1]+v,max(dp[j-a][2]+v,dp[j][1]));
				}
				else{
					dp[j][1] = max(dp[j-a/2][0]+v,dp[j][1]);
					dp[j][2] = max(dp[j-a/2][1]+v,dp[j][2]);
				}*///cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
			/*}
			ll ans = 0;
		for(int i = 1;i<=L;i++){
			//cout<<"ii"<<i<<endl;
			ans = max(ans,dp[i][0]);//cout<<ans<<endl;
			ans = max(ans,dp[i][1]);//cout<<ans<<endl;
			ans = max(ans,dp[i][2]);//cout<<ans<<endl;
		}
		cout<<"Case #"<<++ca<<": ";
		cout<<max(ans1,ans)<<endl;
	}
}*/

