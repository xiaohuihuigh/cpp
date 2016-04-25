/*#include<bits/stdc++.h>
using namespace std;
long long dp[205][205];

int main(){
    int n;
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;dp[1][1] = 1;
    for(int i = 0;i<=205;i++){
        for(int j = 0;j<=i;j++){
            for(int k = 0;k<=i-j&&k<j;k++){
               dp[i][j] =  max(dp[i][j],j*dp[i-j][k]);
               //cout<<i<<" "<<j<<" " <<dp[i][j]<<endl;
            }
        }
    }

    while(cin>>n){
        long long  ans = 0;int maxi;
        for(int i = 1;i<=n;i++){
            ans = max(ans,dp[n][i]);
        }
        cout<<ans<<endl;
    }
}*/
#include<bits/stdc++.h>
using namespace std;
long long ans[205];

int main(){
    int n;
    memset(ans,0,sizeof(ans));

    ans[0] = 1;ans[1] = 1;

    for(int i = 0;i<=205;i++){
       for(int j = 0;j<i;j++){

        ans[i] = max(ans[j]*(i-j),ans[i]);//会有重复，不知道怎么去重
       }
    }

    while(cin>>n){

        cout<<ans[n]<<endl;
    }
}
