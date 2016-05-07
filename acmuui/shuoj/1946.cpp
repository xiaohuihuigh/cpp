#include<iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

int main(){
    ll N;ll c1,c2,c3,sum;
    while(cin>>N){
        if(N == 1)cout<<1<<endl;
        else if(N == 2)cout<<4<<endl;
        else{
            c1 = N;
            c2 = N*(N-1)/2%mod;
            ll n1 = N,n2 = N-1,n3 = N-2;
            if(n1%3 == 0)n1 = n1/3;
            else if(n2%3 == 0)n2 = n2/3;
            else if(n3%3 == 0)n3 = n3/3;
            if(n1%2 == 0)n1 = n1/2;
            else if(n2%2 == 0)n2 = n2/2;
            c3 = n1*n2%mod;
            c3 = c3*n3%mod;
            sum = ((c1+2*c2)%mod+c3)%mod;
            cout<<sum<<endl;
        }
    }
}
