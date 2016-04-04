#include<bits/stdc++.h>
using namespace std;
int qi[2005];
int ti[2005];
int sh[2005];
int main(){
	int n;
	while(cin>>n){
		for(int i = 0;i<n;i++)
			cin>>ti[i];
		for(int i = 0;i<n;i++)
			cin>>qi[i];
		sort(qi,qi+n);
		sort(ti,ti+n);
		int ans = -0x3f3f3f3f;
		for(int j = 0;j<n;j++){
		int cnt = 0;
			for(int i = 0;i<n;i++){
				if(ti[i]>qi[(i+j)%n])cnt+=100;
				else if(ti[i]==qi[(i+j)%n]);
				else cnt-=100;
			}
			ans = max(ans,cnt);
		}


		cout<<ans<<endl;
	}
}
