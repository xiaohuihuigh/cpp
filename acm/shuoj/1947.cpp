
#include<iostream>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
ll dp;
ll fast_mod(ll m,ll n,int mod){
    ll sum = 1;
    while(n){
        if(n&1)sum = sum*m%mod;
        m = m*m%mod;
        n>>=1;
    }
    return sum;
}
int main()
{
    ll N;
    while(cin>>N)
    {
        dp = 1;
        dp = fast_mod(3,N-1,mod);
        cout<<dp<<endl;
    }
}
