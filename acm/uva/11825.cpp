#include<bits/stdc++.h>
using namespace std;
const int maxn = 16;

int s[maxn];
int cover[1<<maxn];
int dp[1<<maxn];
int main(){
    int n;
    int ca = 1;
    while(cin>>n&&n){
        for(int i = 0;i<n;i++){
            int m;
            cin>>m;
            s[i] = 1<<i;
            for(int j = 0;j<m;j++){
                int a;
                cin>>a;
                s[i] |=(1<<a);
            }
        }
        memset(cover,0,sizeof(cover));
        for(int i = 0;i<(1<<n);i++){
            for(int j = 0;j<n;j++){
                if((1<<j)&i){
                    cover[i]|=s[j];
                }
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<(1<<n);i++){
            for(int s0 = i;s0;s0 = (s0-1)&i){
                if(cover[s0] == (1<<n)-1)
                    dp[i] = max(dp[i],dp[s0^i]+1);
            }
        }
        cout<<"Case "<<ca++<<": ";
        cout<<dp[(1<<n)-1]<<endl;
    }
    return 0;
}
