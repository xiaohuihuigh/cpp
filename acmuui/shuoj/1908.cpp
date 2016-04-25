#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
long long dp[25][25];
long long dpss[25];

long long  C(int m,int n,int mod){
    if(dp[m][n]) return dp[m][n];////A
    if(m == n||n == 0)return 1;
    long long ret = (C(m-1,n-1,mod)+C(m-1,n,mod))%mod;
    dp[m][n] = ret;/////B
    return ret;
}

void dps(){
    dpss[0] = 1;
    dpss[1] = 0;
    dpss[2] = 1;
    dpss[3] = 2;
    dpss[4]  = 9;
    for(int i = 5;i<=21;i++){
            dpss[i] = 1;
             for(int k = 1;k<=i;k++)
                dpss[i] *=k;
        for(int j = 1;j<=i;j++){
           dpss[i] -= C(i,j,INF)*dpss[i-j];
        }
    }
}
int main(){
    int n;
    dps();
    while(cin>>n){
            cout<<dpss[n]<<endl;
    }
    return 0;
}
