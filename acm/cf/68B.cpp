//runtime error but not know why
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll  a[1005];
int n,k;
double fun(ll m){
    double ans = 0;
    for (int i = 0;i<n;i++){
    	if(a[i]>m){
            ans += (double)(a[i] - m)*(100 - k)/100;
    	}
    	else {
            ans += (double)(a[i] - m);
    	}
    }
//    cout<<m<<" "<<ans<<endl;
    return ans;
}
int main(){

    while(cin>>n>>k){
        ll l = 1e15,r = 0;
        for (int i = 0;i<n;i++){
            cin>>a[i];
            a[i]*=1e8;
            l = min(a[i],l);
            r = max(a[i],r);
        }
        while(l<r){
            ll mid = (l+r-1)/2+1;
            if(fun(mid)>= 0)l = mid;
            else r = mid-1;
        }s
//        cout<<l<<endl;
        printf("%.7lf\n",l/1e8);
//        cout<<(double)l/10000000<<endl;
    }
}
