#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int dp[550][550];
int sum[550];
int main(){
	int m,k;
	int a[550];
	int ca = 1;
	while(cin>>m>>k){
		memset(sum,0,sizeof(sum));
		for(int i = 1;i<=m;i++){
			cin>>a[i];
			sum[i]=a[i]+sum[i-1];
		}
		memset(dp,INF,sizeof(dp));
		for(int i = 1;i<=m;i++){
			dp[1][i] = sum[i];
		}
		for(int i = 2;i<=k;i++){
			for(int j = i;j<=m-(k-i);j++){
				for(int k1 = i-1;k1<j;k1++){
					int t = max(dp[i-1][k1],sum[j] - sum[k1]);
					dp[i][j] = min(t,dp[i][j]);

					/*dp[i][j] = min(dp[i-1][k1],dp[i][j]);
					dp[i][j] = max(sum[j] - sum[k1],dp[i][j]);*/
				}
			}
		}
		cout<<"Case "<<ca++<<": ";
		cout<<dp[k][m]<<endl;
	}
}
/*#include<bits/stdc++.h>
using namespace std;
int dp[550][550];
int sum[550];
int main(){
	int m,k;
	int a[550];
	int ca = 1;
	while(cin>>m>>k){
		memset(sum,0,sizeof(sum));
		for(int i = 1;i<=m;i++){
			cin>>a[i];
		}

		for(int i = 1;i<=m;i++){
			sum[i]=a[i]+sum[i-1];
		}
		memset(dp,0,sizeof(dp));
		for(int i = 1;i<=m;i++){
			dp[1][i] = sum[i];
		}
		for(int i = 2;i<=k;i++){
			for(int j = i;j<=m-(k-i);j++){
				for(int k1 = i-1;k1<j;k1++){
					int t = max(dp[i-1][k1],sum[j] - sum[k1]);
					dp[i][j] = min(t,dp[i][j]);
				}
			}
		}
		cout<<"Case "<<ca++<<": ";
		cout<<dp[k][m]<<endl;
	}
}
*/
// 复制书稿
/*
int main()
{
	int m, k, i, j, n, min, temp, sum, count = 1;
	int F[550][550];

	while (~scanf("%d%d", &m, &k)) {

		for (i = 0; i < m; i++)
			scanf("%d", &F[0][i]);
		F[1][0] = F[0][0];
		for (i = 1; i < m; i++)
			F[1][i] = F[1][i - 1] + F[0][i];
		for (i = 2; i <= k; i++) {
			for (j = 0; j < m; j++) {
				if (i > j + 1)
					F[i][j] = F[i - 1][j];
				else {
					min = F[1][j];
					sum = 0;
					for (n = j; n >= 0; n--) {
						sum += F[0][n];
						temp = sum < F[i - 1][n - 1] ? F[i - 1][n - 1] : sum;
						if (min >= temp)
							min = temp;
						else
							break;
					}
					F[i][j] = min;
				}
			}
		}
		for (i = 1; i <= k ; i++)
			if (!F[i][m- 1])
				break;
		if (m < 1)
			temp = 0;
		else
			temp = F[i - 1][m - 1];
		printf("Case %d:%d/n", count++, temp);
	}

	return 0;
}*/
