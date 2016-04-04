#include<bits/stdc++.h>
using namespace std;
long long t[200005];
int main(){
	int n,b;
	cin>>n>>b;
		t[0] = 0;
		for(int i = 1;i<=n;i++){
		if(i!= 1)cout<<" ";
			long long x,y;
			cin>>x>>y;
			if(i<=b){cout<<max(x+y,t[i-1]+y);t[i] = max(x+y,t[i-1]+y);}
			else{
				if(x<t[i-b-1]){cout<<"-1";i--;n--;}
				else{cout<<max(x+y,t[i-1]+y);t[i] = max(x+y,t[i-1]+y);}
			}
		}
		cout<<endl;
}


