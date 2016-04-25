#include<bits/stdc++.h>
using namespace std;
int a[105];
int dp[105][105];

int main(){
    int n;
    while(cin>>n){
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        memset(dp,0,sizeof(dp));
        for(int k  =0;k<n;k++)
        for(int i  = n-1;i>=0;i--){
            for(int j = 0;j<n-2;j++){
                int t = i+2+j;
                //if(t%n == i-1)break;
                    //if(j-i<2)continue;
                if((t-i)%n == 2){
                    dp[i][t%n] = a[i]*a[(i+1)%n]*a[t%n];
               //   continue;
                }
                dp[i][t%n] = max(dp[(i+1)%n][t%n]+a[i]*a[(i+1)%n]*a[t%n],max(dp[i][(t-1)%n]+a[t%n]*a[(t-1)%n]*a[i],dp[i+1][(t-1)%n]+a[i]*a[(i+1)%n]*a[(t-1)%n]+a[(i+1)%n]*a[t%n]*a[(t-1)%n]));
            }

        }
        int ans = 0;
        for(int i  = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                //int t = i+2+j;
                if(i == j) continue;
                ans = max(ans,dp[i][j]+dp[j][i]/*+max(a[i]*a[i]*a[j],a[i]*a[j]*a[j])*/);
                cout<<i<<" "<<j<<" "<<dp[i][j]<<" ";
            }cout<<endl;}
        //for(int i = 0;i<n;i++)ans = max(ans,dp[i][i]/*+(a[i]*a[(i-1+n)%n]*a[i])*/);
        cout<<ans<<endl;
    }
}
