#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 110;
int p[maxn];
int h[maxn];
int dp[maxn];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(dp,INF,sizeof(dp));
		/**记录节点从 1开始，思考更方便（统一dp和p，h的索引）*/
		for(int i = 1;i<=n;i++) cin>>p[i]>>h[i];
		/**初始化dp[0]是为dp[1]服务*/
		dp[0] = 0;
		for(int i = 1;i<=n;i++){
			/*r和l的作用是不一样的，向左和向右的思路是不一样的。因为向右为正序，更新后的r
			为向右推倒的最大位置。向左为逆序，l表示当前要被推到的位置。所以在向右的时候else
			要break，因为再进行下去已经没有意义了。而向左则不一样，即使位置较大的p也可能推到当前的位置。
			这样就有一个弊端，dp[i]并不一定为推到i的最小次数（好像也没什么卵用）不用管**/
			int r = p[i]+h[i];
		for(int j = i;j<=n;j++){
			if(p[j]<r){
				dp[j] = min(dp[j],dp[i-1]+1);
				r = max(p[j]+h[j],r);
			}
			else    break;
		}
		int l = p[i];
		for(int j = i;j<=n;j++){
			if(p[j] - h[j] < l){
				dp[j] = min(dp[j],dp[i-1]+1);
				l = p[j];
			}

		}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
