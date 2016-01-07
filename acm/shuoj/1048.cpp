#include<bits/stdc++.h>
using namespace std;
long long bin[35];
int a[11];
int main(){
	long long  k,N;
	cin>>k>>N;
	bin[0] = 1;
	for(int i = 1;i<=33;i++)bin[i] = bin[i-1]<<1;
	int t = 0;
	while(N>0)
		for(int i = 10;i>=0;i--)
			if(N>=bin[i]&&N<bin[i+1]){
				a[t++] = i;
				N -=bin[i];
			}
	long long  ans = 0;long long mod = bin[32];
	for(int i = 0;i<t;i++)ans+= (long long)pow(k,a[i])%mod;
	cout<<ans%mod<<endl;

}
