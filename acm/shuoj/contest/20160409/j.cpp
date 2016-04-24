#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		double t = sqrt(n*1.0);
		//cout<<t;
		int tt = (int )t;
		if(tt == t)tt--;
		if(n&1){
			cout<<n-tt-1<<endl;
		}
		else{
			cout<<n-tt<<endl;

		}
	}
}
