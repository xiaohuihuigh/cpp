#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans = 0;
		while(n){
			if(n&1)ans++;
			n>>=1;
		}
		cout<<(1<<ans)<<endl;
	}
}
