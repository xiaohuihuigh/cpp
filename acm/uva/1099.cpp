#include<bits/stdc++.h>
using namespace std;
const int maxn = 17;
int a[maxn];
int sum[1<<maxn];
int dp[1<<maxn][105];

int low_bit(int x){
    return x&(-x);
}
int bitcount(int x){
    if(x == 0)return 0;
    return bitcount(x>>1)+(x&1);
}
int count_bit(int x){
    int cnt = 0;
    while(x){
        cnt++;
        x-=low_bit(x);
    }
    return cnt;
}

int dfs(int s,int x){
    if(dp[s][x]!=-1)return dp[s][x];
    if(count_bit(s) == 1)return dp[s][x] = 1;
    int y = sum[s]/x;
    for(int s0 = (s-1)&s;s0;s0 = (s0-1)&s){
        int s1 = (s0^s);
        if(sum[s0]%x == 0&&dfs(s0,min(x,sum[s0]/x))&&dfs(s1,min(x,sum[s1]/x)))
            return dp[s][x] = 1;
        if(sum[s0]%y == 0&&dfs(s0,min(y,sum[s0]/y))&&dfs(s1,min(y,sum[s1]/y)))
            return dp[s][x] = 1;
    }
    return dp[s][x] = 0;
}
int main(){
    int n;
    int ca = 1;
    while(cin>>n&&n){
        int x,y;
        cin>>x>>y;
        memset(sum,0,sizeof(sum));
        for(int i =0;i<n;i++)cin>>a[i];
        for(int s = 1;s<(1<<n);s++)
        for(int i = 0;i<n;i++)
            if(s&(1<<i))sum[s]+=a[i];
        int flag = 1;
        int all = (1<<n)-1;
        memset(dp,-1,sizeof(dp));
        if(sum[all] != x*y||sum[all]%x)flag = 0;
        else if(!dfs(all,min(x,y)))flag = 0;
        cout<<"Case "<<ca++<<": ";
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
