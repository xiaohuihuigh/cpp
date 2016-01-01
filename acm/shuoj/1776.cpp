#include<bits/stdc++.h>
using namespace std;
int dp[45];
void qiudp(){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for(int i = 3;i<=45;i++ ){
        dp[i] = dp[i-1]+dp[i-2];
    }
}

int main(){
    int n;
    qiudp();
    while(cin>>n){


        cout<<dp[n]<<endl;
    }
}
