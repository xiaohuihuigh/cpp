#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

int maps[23][1005];
int dp[23][1005];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        memset(maps,0,sizeof(maps));
        memset(dp,-INF,sizeof(dp));//初始化不能是0
        dp[1][0] = 0;//保证dp[1][1] = 0;
        dp[0][1] = 0;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++){
                scanf("%d",&maps[i][j]);
            }
        }
        for(int i = 1;i<=n;i++)
        {

            for(int j = 1;j<=m;j++){
                     dp[i][j] =max(dp[i-1][j],dp[i][j-1]);
                    for(int k = 1;k*k<=j;k++){
                        if(j%k == 0){
                            dp[i][j] = max(dp[i][j],max(dp[i][j/k],dp[i][k]));
                        }
                    }
                dp[i][j] = dp[i][j]+maps[i][j];
            }
        }
        cout<<dp[n][m]<<endl;

    }
}
