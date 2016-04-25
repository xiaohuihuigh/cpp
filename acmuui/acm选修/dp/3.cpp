#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
int maps[50][50];
int dp[50][50];
int main(){
    int n,m;
    while(cin>>n>>m){
        memset(maps,-1,sizeof(maps));
        memset(dp,-1,sizeof(dp));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>maps[i][j];
                }
            }
        for(int i = 1;i<=n;i++){
            
            for(int j = 1;j<=m;j++){
                
                if(maps[i][j] == -1){dp[i][j] = -1;continue;}
                if(dp[i-1][j] == -1&&dp[i][j-1] == -1)dp[i][j] = -1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1])+maps[i][j];
                dp[1][1] = maps[1][1];
                }
            }
           /* for(int i = 1;i<=n;i++){
            
            for(int j = 1;j<=m;j++){
                cout<<dp[i][j]<<" ";
                }
                cout<<endl;}*/
            if(dp[n][m] == -1)cout<<"Impossible"<<endl;
            else cout<<dp[n][m]<<endl;
            
        }
    
        
        
    }
