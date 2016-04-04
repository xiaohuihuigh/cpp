#include<bits/stdc++.h>
using namespace std;
int main(){
	long long  x,y,m,n,L;
	cin>>x>>y>>m>>n>>L;
	if(m>n){
		long long dis = y-x;
		if(dis<0) dis+=L;
		long long v = m-n;
		long long ans = (dis+v-1)/v;
		cout<<ans<<endl;
	}
	else if(m == n){
		cout<<"Impossible"<<endl;
	}
	else{
		long long dis = x-y;
		if(dis<0) dis+=L;
		long long v = n-m;
		long long ans = (dis+v-1)/v;
		cout<<ans<<endl;
	}
}
