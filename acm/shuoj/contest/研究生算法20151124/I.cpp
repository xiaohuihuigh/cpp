#include<bits/stdc++.h>
using namespace std;
const int mod = 1000007;
long long dp[405][405];

//将组合数打表
void com(){
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2;i<401;i++){
        for(int j = 0;j<=i;j++){
            if(j == 0||j == i)dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
}
int main(){
    com();
    int T;
    cin>>T;
    while(T--){
        int m,n,k;
        cin>>m>>n>>k;
         if(k<2||k>m*n)
        {
            cout<<0<<endl;
            continue;
        }
      long long sum;
      sum = (dp[n*m][k] - 2*dp[0

              9\1422n-1)*m][k] - 2*dp[n*(m-1)][k]+mod)%mod;
      while(sum<0)sum+=mod;
      sum = (sum + dp[(n-2)*m][k] + dp[(m-2)*n][k] + 4 * dp[(n-1)*(m-1)][k])%mod;
      while(sum<0)sum+=mod;
      sum = (sum - 2*dp[(n-2)*(m-1)][k] - 2*dp[(m-2)*(n-1)][k]+mod)%mod;
      while(sum<0)sum+=mod;
      sum = (sum + dp[(n-2)*(m-2)][k])%mod;
      while(sum<0)sum+=mod;
        cout<<sum<<endl;
    }
}
