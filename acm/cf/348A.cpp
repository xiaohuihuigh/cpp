#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll a[100005];
int main(){
    int n;
//    cin>>n;
    ll sum = 0;
    ll ans = 0;
    while(cin>>n){
        for(int i = 0;i<n;i++){
            ll t;
            cin>>t;
            ans = max(ans,t);
            sum+=t;
        }
        ans = max(ans,(sum-1)/(n-1)+1);
        cout<<ans<<" "<<sum<< endl;

    }
}
