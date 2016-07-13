#include<bits/stdc++.h>
using namespace std;
#define rep(i,to) for(int i=0;i<(to);++i)
#define ios        ios::sync_with_stdio(false)
#define pb        push_back

#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define mp        make_pair
#define F         first
#define S         second
typedef long long ll;
const int maxn = 100500;
ll a[maxn];
ll sum[maxn];
set<ll> used;

ll fun(ll n){

}
int main(){
    ios;
    int n,k;
    while (cin>>n>>k){
    	rep(i,n){
    		cin>>a[i];
    	}
    	sort(a,a+n);
    	sum[0] = 0;
    	rep(i,n){
            sum[i+1] = sum[i]+a[i];
    	}
    	int cnt = -1,ans = -1;
    	rep(i,n){
            ll l = -1,r = i+1;
            while(l<r){
                ll mid = (l+r-1)/2+1;

                ll kk = a[i]*mid - (sum[i+1] - sum[1+i - mid]);
                cout<<i<<" "<<mid<<" "<<kk<<" "<<sum[i] - sum[i - mid]<<endl;
                if(kk>k){r = mid-1;}
                else{
                    l = mid;
                }
            if(l>cnt){
                cnt = l;
                ans = a[i];
            }
//            while(a[i]*l - (sum[i+1] - sum[1+i - l])<=k)
//            if(l<=i+1)l++;else break;
////            cout<<r<<endl;
//            if(l-1>cnt){
//                cnt = l-1;
//                ans = a[i];
            }
    	}
    	cout<<cnt<<" "<<ans<<endl;
    }
}
