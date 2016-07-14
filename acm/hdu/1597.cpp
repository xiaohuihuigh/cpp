
#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        n*=2;
        ll l = 0;ll r = 1<<16;
//no_left,ok_right
        while(l<r){
            ll mid = (l+r-1)/2+1;
            if(mid*(mid+1)<=n) l = mid;
            else r = mid-1;
        }
//        cout<<"l"<<l<<endl;
        int t = (n - l*(l+1))/2;
        if(t == 0){
            cout<<(l-1)%9+1<<endl;
        }
        else{
            cout<<(t-1)%9+1<<endl;
        }
    }

}
