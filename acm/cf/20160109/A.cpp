#include<bits/stdc++.h>
using namespace std;
int nn[140];
int main(){
	int n,m;
	while(cin>>n>>m){
	memset(nn,0,sizeof(nn));
	for(int i = 0;i<n;i++){
	int a;
	cin>>a;
		for(int j = 0;j<a;j++){
			int b;
			cin>>b;
			b--;
			nn[b] = 1;
		}
	}int ans = 0;
	for(int i = 0;i<m;i++){
		if(nn[i] == 1)ans++;
	}
	if(ans==m)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	}


}
