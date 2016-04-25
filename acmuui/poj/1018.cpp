#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 110;
int b[maxn];
int p[maxn];
int dp[maxn][1205];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m;
		scanf("%d",&m);
		int maxb = 0;int n;
		memset(dp,inf,sizeof(dp));
		memset(b,0,sizeof(b));
		memset(p,0,sizeof(p));
		for(int i = 1;i<=m;i++){
			scanf("%d",&n);

			for(int j = 1;j<=n;j++){
				scanf("%d%d",&b[j],&p[j]);
				maxb = max(maxb,b[j]);
			}
			if(i == 1){
				for(int j = 1;j<=n;j++)dp[1][b[j]] = p[j];
				continue;
			}
			int tem;
			for(int k = 1;k<=maxb;k++){
				for(int j = 1;j<=n;j++){
					tem = min(k,b[j]);
					dp[i][tem] = min(dp[i][tem],dp[i-1][k]+p[j]);
				}}
		}
		double ans = 0;
		for(int i = 1;i<=maxb;i++){
				ans = max(ans,1.0*i/dp[m][i]);
		}
		printf("%.3f\n",ans);
	}
	return 0;
}
