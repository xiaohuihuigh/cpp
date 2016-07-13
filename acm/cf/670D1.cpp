#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll a[maxn];
ll b[maxn];
int main(){
    ios::sync_with_stdio(false);
    int n,k;
    while(cin>>n>>k){
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        for (int i = 0;i<n;i++){
        	cin>>b[i];
        }
        ll l = 0,r = 1e10;
        while(l<r){
            ll mid = (l+r-1)/2+1;
            ll need = 0;
            for(int i= 0;i<n;i++){
                need+=max(0ll,a[i]*mid - b[i]);
                if (need>k)break;
            }
//            cout<<need<<endl;
            if(need<=k)l = mid;
            else r = mid - 1;
        }
        cout<<l<<endl;
    }
}

