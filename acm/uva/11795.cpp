#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str[20];
ll s[20];
ll st[1<<17];
ll dp[1<<17];
void str_to_ll(ll i){
    for(ll t = 0;t<str[i].length();t++){
        if(str[i][t] == '1')
            s[i] |= 1<<t;
    }
}
int main(){
    ll T;
    ll ca = 1;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        memset(s,0,sizeof(s));
        memset(st,0,sizeof(st));
        memset(dp,0,sizeof(dp));
        for(ll i = 0;i<=n;i++){
            cin>>str[i];
            str_to_ll(i);
        }
        st[0] = s[0];
        for(ll i = 0;i<(1<<n);i++){
            st[i] = st[0];
            for(ll j = 0;j<n;j++){
                if((1<<j)&i)
                    st[i]|=s[j+1];
            }
        }
//        for(ll i = 0;i<(1<<n);i++){
//            cout<<st[i]<<" "<<i<<endl;
//        }

        dp[0] = 1;
        for(ll i = 1;i<(1<<n);i++){
            dp[i] = 0;
            for(ll j = 0;j<n;j++){
               if(((1<<j)&i)&&(st[i^(1<<j)]&(1<<j))){
                    dp[i] += dp[i^(1<<j)];
               }
            }
        }
//        for(ll i = 0;i<(1<<n);i++){
//            cout<<dp[i]<<" "<<i<<endl;
//        }
        cout<<"Case "<<ca++<<": ";
        cout<<dp[(1<<n)-1]<<endl;
    }
}
