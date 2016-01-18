//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;
int c[510][510];
const int mod = 1000007;
void CC(){
	memset(c,0,sizeof(c));
	for(int i = 0;i<=500;i++){
		c[i][0] = 1;
		for(int j = 1;j<=i;j++){
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	/*for(int i = 0;i<=10;i++){
		for(int j = 0;j<=i;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}*/
}


int main(){
	int T;
	CC();
	cin>>T;
	int ca = 1;
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		long long  ans = 0;

		ans = c[n*m][k];
		ans  = ans-2*c[(n-1)*m][k]-2*c[(m-1)*n][k]+4*c[(n-1)*(m-1)][k]+c[(m-2)*n][k]+c[(n-2)*m][k];
		ans = (ans+mod)%mod;
		ans = ans-2*c[(m-2)*(n-1)][k]-2*c[(m-1)*(n-2)][k]+c[(n-2)*(m-2)][k]%mod;
		while(ans<0)ans+=mod;
		ans%=mod;
		cout<<"Case "<<ca++<<": ";
		cout<<ans<<endl;
	}
}
