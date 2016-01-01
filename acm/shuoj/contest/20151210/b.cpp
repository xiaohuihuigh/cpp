#include<iostream>
using namespace std;
long long dp[100];
void dppp(){
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3;i<60;i++){
        dp[i] = dp[i-1]+dp[i-3]+1;

    }
}

int main(){
    dppp();
    int n;
    while(cin>>n){
        cout<<dp[n]<<endl;
    }
}
