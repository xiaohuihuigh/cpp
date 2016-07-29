
#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[1040][30];//dp[i][j]表示第i段中第j个字母为结尾时的最少chunks
int cnt[1040];//记录每一段有多少chunks
set<int> v[1040];
int fc(int x,int t){
    set<int>::iterator it = v[x].begin();
    for(int i = 0;i< t;i++)
        it++;
    return *it;
}
int cti(char s){//char_to_int
    int t = s - 'a';
    return t;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int k;
        string s;
        cin>>k>>s;
        memset(cnt,0,sizeof(cnt));
        int n = s.length()/k;
        for(int i = 0;i<n;i++)v[i].clear();
        for(int i = 0;i<s.length();i++){
            int t = i/k;
            if(v[t].find(cti(s[i])) == v[t].end()){
                cnt[t]++;
                v[t].insert(cti(s[i]));
            }
        }
        memset(dp,INF,sizeof(dp));
        for(int i = 0;i < cnt[0];i++)dp[0][i] = cnt[0];
        for(int i = 1;i<n;i++)
            for(int j = 0;j<cnt[i];j++)
                for(int k = 0;k<cnt[i-1];k++)
                    if(cnt[i] == 1&&fc(i,j) == fc(i-1,k))
                        dp[i][j] = min(dp[i][j],dp[i-1][k]+cnt[i]-1);
                    else if(cnt[i]!= 1&&fc(i,j)!= fc(i-1,k))
                        if(v[i].find(fc(i-1,k))!=v[i].end())
                            dp[i][j] = min(dp[i][j],dp[i-1][k]+cnt[i]-1);
                        else
                            dp[i][j] = min(dp[i][j],dp[i-1][k]+cnt[i]);
                    else
                        dp[i][j] = min(dp[i][j],dp[i-1][k]+cnt[i]);
        int ans = INF;
        for(int i = 0;i<cnt[n-1];i++)
            ans = min(ans,dp[n-1][i]);
        cout<<ans<<endl;
    }
    return 0;
}
