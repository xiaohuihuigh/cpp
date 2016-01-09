#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[200050];
map<int ,ll>MA;
const ll mod = 1e9+7;
ll fast_mod(ll n,ll m,ll mod){
	ll ans =1;
	while(m){
		if(m&1)ans = ans*n%mod;
		m>>=1;
		n = n*n%mod;
	}
	return ans;
}
int main(){
	int T;
	cin>>T;
	MA.clear();
	for(int i = 0;i<T;i++){
		int a;
		scanf("%d",&a);
		MA[a]++;
	}
	map<int,ll>::iterator it;
	ll sum = 1;
	ll ans = 1;
	for(it = MA.begin();it!=MA.end();it++){
		int cnt = fast_mod(it->first,(it->second+1)*it->second/2,mod);
		ans=fast_mod(ans,it->second+1,mod)*fast_mod(cnt,sum,mod)%mod;
		sum=sum*(it->second+1)%(mod-1);
	}
	printf("%I64d\n",ans);
}/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[200050];
map<int ,ll>MA;
const ll mod = 1e9+7;
ll fast_mod(ll n,ll m,ll mod){
    ll ans =1;
    while(m){
        if(m&1)ans = ans*n%mod;
        m>>=1;
        n = n*n%mod;
    }
    return ans;
}
int main(){
    int T;
    cin>>T;
    for(int i = 0;i<T;i++){
        int a;
        scanf("%d",&a);
        MA[a]++;
    }
    map<int,ll>::iterator it;
    ll sum = 1;
    for(it = MA.begin();it!=MA.end();it++){
        sum*=(it->second+1);
    }
    ll ans = 1;
    for(it = MA.begin();it!=MA.end();it++){
        int cnt = (it->second+1)*it->second/2%(mod-1)*sum/(it->second+1)%(mod-1);
        ans=ans*fast_mod(it->first,cnt,mod)%mod;
    }
    printf("%I64d\n",ans);
}*/
