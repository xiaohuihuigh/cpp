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
set<ll> used;

int main(){
    ios;
    int n,d;
    cin>>n>>d;
    rep(i,n)cin>>a[i];
    int j = 0;
    ll ans = 0;
    rep(i,n){
        while(a[i] - a[j]>d)j++;
        ans+=(ll) (i-j)*(i-j-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}

