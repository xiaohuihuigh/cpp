#include<bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int s[maxn];
int dp[maxn];
int len,n,m;
bool fun(int sk){
    dp[0] = 0;
    for(int i = 1;i<n;i++){
        int l = 0,r = i-1;
        while(l<r){
            int mid = (l+r)/2;
            if(s[i] - s[mid]<=sk) r = mid;
            else l = mid+1;
        }
        dp[i] = dp[r]+1;
        if(dp[i]>m)return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>len>>n>>m){
        s[0] = 0;
        int l = 0;
        for(int i = 1;i<=n;i++){
            cin>>s[i];

        }
        s[n+1] = len;
        n+=2;
        sort(s,s+n);
        for(int i = 1;i<n;i++){
            l = max(l,s[i] - s[i-1]);
        }
        int r = len;
        while(l<r){
            int mid = (l+r)/2;
//            fun(mid);
//            cout<<fun(mid)<<mid<<endl;
            if(fun(mid)) r = mid;
            else l = mid+1;
        }
        cout<<r<<endl;
    }
}
// 1000000000
