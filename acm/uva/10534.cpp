#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int a[maxn];
int b[maxn];
int dp[maxn];
int cnt1[maxn];
int cnt2[maxn];
int n;

int lis(int *a){
    int len = 1;dp[1] = a[0];
    cnt1[0] = 1;
    for(int i = 1;i<n;i++){
        int t = a[i];
        if(t>dp[len]){dp[++len] = a[i];cnt1[i] = len;}
        else{
            int p = lower_bound(dp+1,dp+len+1,t)-dp;
            dp[p] = t;
            cnt1[i] = p;
        }
    }
    return len;
}
int main(){
    while(cin>>n){
        for(int i = 0;i<n;i++){
            cin>>a[i];
            b[n-1-i] = a[i];
        }
        int len1 = lis(a);
        for(int i = 0;i<n;i++){
            cnt2[i] = cnt1[i];
        }
        int len2 = lis(b);
       /* for(int i = n-1;i>=0;i--)
            cout<<cnt1[i]<<" ";
        cout<<endl;
        for(int i = 0;i<n;i++)
            cout<<cnt2[i]<<" ";
        cout<<endl;*/
        int ans = 0;
        for(int i = 0;i<n;i++){
            int mi = min(cnt2[i],cnt1[n-1-i]);
            ans = max(mi,ans);
        }
        cout<<ans*2-1<<endl;
    }
}
