#include<bits/stdc++.h>
using namespace std;
long long dp[35][35];
const int INF = 0x3f3f3f;


long long  C(int m,int n,int mod){
    if(dp[m][n]) return dp[m][n];////A
    if(m == n||n == 0)return 1;
    long long ret = (C(m-1,n-1,mod)+C(m-1,n,mod))%mod;
    dp[m][n] = ret;/////B
    return ret;
}

int main(){
    int n,m;
    while(cin>>n>>m){
        long long num = 0;
      for(int i = 1;i <= n;i++){
            if(i<=m)
           num += C(m,i,INF)*C(n-1,i-1,INF);
        }
        cout<<num<<endl;
    }
}
