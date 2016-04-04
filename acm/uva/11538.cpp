#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define REP(X,N) for(int X = 0;X<N;X++)
typedef long long ll;

int main(){
	ll  n,m;
	while(cin>>n>>m&&n&&m){
		if(n>m)swap(n,m);
		ll ans = n*m*(n+m-2)+2*n*(n-1)*(m-n+1)+4*(n*(n-1)*(2*n-1)/6-n*(n-1)/2);
		cout<<ans<<endl;
	}
}
