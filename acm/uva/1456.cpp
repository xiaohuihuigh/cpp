#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int p[maxn];
int pre[maxn];
int dp[maxn][maxn];

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,w;
        cin>>n>>w;
        memset(pre,0,sizeof(pre));
        pre[0] = 0;
        for(int i = 1;i<=n;i++)cin>>p[i];
        sort(p+1,p+n+1,greater<int>());
        for(int i = 1;i<=n;i++)pre[i] = pre[i-1]+p[i];
        memset(dp,INF,sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1;i<=w;i++){
            for(int j = 1;j<=n;j++){
                for(int k = 1;k<=n;k++){
                    dp[i][j] = min(dp[i][j],dp[i-1][k-1]+j*(pre[j] - pre[k-1]));
                }
            }
        }
        double ans = dp[w][n]*1.0/pre[n];
        printf("%.4lf\n",ans);
    }
}
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 105;
//const int INF = 0x3f3f3f3f;
//int p[maxn];
//int pre[maxn];
//int dp[maxn][maxn];
//
//int main(){
//    int T;
//    cin>>T;
//    while(T--){
//        int n,w;
//        cin>>n>>w;
//        memset(pre,0,sizeof(pre));
//        pre[0] = 0;
//        for(int i =1;i<=n;i++)cin>>p[i];
//        sort(p+1,p+n+1,greater<int>());
//        for(int i = 1;i<=n;i++)pre[i] = pre[i-1]+p[i];
////        memset(dp,INF,sizeof(dp));
//        for(int i = 1; i <= n; ++i){
//            dp[i][0] = INF;
//            for(int j = 1; j <= w; ++j){
//                dp[i][j] = INF;
//                for(int k = 1; k <= i; ++k)
//                    dp[i][j] = min(dp[i][j], dp[k-1][j-1] + i*(pre[i]-pre[k-1]));
//            }
//        }
//        double ans = dp[n][w]*1.0/pre[n];
//        printf("%.4lf\n",ans);
////        cout<<dp[w-1][n-1]
//    }
//}
