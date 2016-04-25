//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[1000][1000];
int dp[1000][1000];
int main(){
    int T;
    while(cin>>T){
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i = 1;i<=T;i++){
            for(int j = 2;j<=i*2;j++){
                cin>>a[i][j];
                }
            }
            dp[0][0] = 0;dp[0][1] = 0;dp[0][2] = 0;
        for(int i = 1;i<=T;i++){
            for(int j = 2;j<=i*2;j++){
                dp[i][j] = max(dp[i-1][j],max(dp[i-1][j-2],dp[i-1][j-1]))+a[i][j];
                }
            }
            /*for(int i = 1;i<=T;i++){
            for(int j = 2;j<=i*2;j++){
                cout<<dp[i][j]<<" ";
                }
                cout<<endl;
            }*/
            int ans = -INF;
            
        for(int i = 2;i<=T*2;i++){
            ans = max(dp[T][i],ans);
            }
            cout<<ans<<endl;
        }      
}
