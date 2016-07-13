#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nb,ns,nc,pb,ps,pc;
int rb,rs,rc;
ll fun(ll c){
    ll cost = 0;
    cost+=max(rb*c - nb,0ll)*pb;
    cost+=max(rs*c - ns,0ll)*ps;
    cost+=max(rc*c - nc,0ll)*pc;
    return cost;
}

int main(){
    string s;
    ios::sync_with_stdio(false);
    while(cin>>s){

        rb =  count(s.begin(),s.end(),'B');
        rs =  count(s.begin(),s.end(),'S');
        rc =  count(s.begin(),s.end(),'C');
        ll t;
        cin>>nb>>ns>>nc>>pb>>ps>>pc>>t;
        ll l = 0,r = 1e15;
        while(l<r-1){
            ll mid = (l+r)/2;
            if(fun(mid)>t)r = mid;
            else l = mid;
        }
        cout<<l<<endl;
    }
//999999999999999
}
