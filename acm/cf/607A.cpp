#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int b[maxn],dp[maxn];
int main(){
    ios::sync_with_stdio(false);

    int n;
    while(cin>>n){
        memset(b,0,sizeof(b));
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<n;i++){
            int a;
            cin>>a;
            cin>>b[a];
        }
        if(b[0]>0)dp[0] = 1;
        int mx = 0;
        for (int i = 1;i<maxn;i++){
        	if(b[i] == 0){
                dp[i] = dp[i-1];
        	}else{
                if(b[i]>=i){
                    dp[i] = 1;
                }else{
                    dp[i] = dp[i - b[i] - 1] +1;
                }
        	}
        	mx = max(mx,dp[i]);
        }
        cout<<n - mx<<endl;
    }
}
