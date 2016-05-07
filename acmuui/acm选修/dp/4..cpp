#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20][20];
int dp[20][20];
int main(){
    int n,m;
    while(cin>>n>>m){
        for(int i = 0;i<n;i++){
            for(int j  =0;j<m;j++){
                cin>>a[i][j];
                }
            }
            int sum = 0;
            for(int k = 0;k<n;k++){
                memset(dp,0,sizeof(dp));
            for(int i = 0;i<m;i++){
            for(int j  =i;j>=0;j--){
                if(i == j)dp[i][j] = a[k][i]*2;
                //else if(j-i == 1)dp[i][j] = max(dp[][]2+a[k][j],a[k][i]+a[k][j]*2);
                else
                dp[i][j] = max(dp[i-1][j]+a[k][i],dp[i][j+1]+a[k][j])*2;
                }
            }
            sum +=dp[m-1][0];
            }
            /*for(int i = 0;i<m;i++){
            for(int j  =0;j<m;j++){
               cout<<dp[i][j]<<" "; }

            cout<<endl;}*/
            cout<<sum<<endl;

        }

    }
