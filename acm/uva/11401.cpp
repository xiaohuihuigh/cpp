#include<bits/stdc++.h>
using namespace std;
#define REP(X,N) for(int X = 0;X<N;X++)
typedef long long ll;
ll t[1000010];
int main(){
	ll n;
	t[3] = 0;
	for(long long i = 4;i<1000001;i++){
		t[i] = t[i-1]+((i-2)*(i-1)/2-(i-1)/2)/2;
	}
	while(cin>>n){
		if(n<3)break;
		cout<<t[n]<<endl;
	}
	return 0;
}
