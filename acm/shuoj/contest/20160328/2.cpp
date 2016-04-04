#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) {
	ll c;
	if(a ==0) return b;
   while(b!=0) c=b,b=a%b,a=c;
   return a;
}
int main(){
	ll T;
	cin>>T;
	while(T--){
		ll n ;
		cin>>n;
		ll a;ll b;
		cin>>a;
		for(ll i = 0;i<n-1;i++){
			cin>>b;
			ll t = gcd(a,b);
			a = a*b/t;
		}
		cout<<a<<endl;
	}
}
