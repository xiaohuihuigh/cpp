#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		string s[105];int ans = 0;
		for(int i = 0;i<n;i++)cin>>s[i];
		for(int i = 0;i<n;i++){
		int cnt = 0;
		for(int j =0;j<n;j++){
			if(s[i][j] =='C')cnt++;
		}
		ans+= (cnt*(cnt-1)/2);
		}
		for(int i = 0;i<n;i++){
		int cnt = 0;
		for(int j =0;j<n;j++){
			if(s[j][i] =='C')cnt++;
		}
		ans+= (cnt*(cnt-1)/2);
		}
		cout<<ans<<endl;
	}
}
