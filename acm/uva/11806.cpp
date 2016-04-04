#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i = 0;i<n;i++)
typedef long long ll;
ll c[510][510];
ll mod = 1000007;

int main(){
	memset(c,0,sizeof(c));
	c[0][0] = 1;
	REP(i,500){
		c[i][0] = c[i][i] = 1;
		for(int j = 1;j<i;j++){
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	int T;
	cin>>T;
	int ca = 1;
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		ll sum = 0;
		REP(i,16){
			int b = 0,h = n,l = m;
			if(i&1){h--;b++;}
			if(i&2){h--;b++;}
			if(i&4){l--;b++;}
			if(i&8){l--;b++;}
			if(b&1){sum = (sum - c[h*l][k])%mod;}
			else{sum = (sum+c[h*l][k])%mod;}
		}
		while(sum<0)sum = (sum+mod)%mod;
		cout<<"Case "<<ca++<<": "<<sum<<endl;

	}
}






