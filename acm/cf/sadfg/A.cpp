#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b;
	while(cin>>n>>a>>b){
		if(n>a*b){cout<<"-1"<<endl;continue;}
		if(b%2){
		int cnt = 1;
			for(int i = 1;i<=a;i++){
				for(int j = 1;j<=b;j++){
					if(j!= 1)cout<<" ";
					if(cnt<=n)cout<<cnt++;
					else cout<<0;
				}
				cout<<endl;
			}
		}
		else{
			int cnt = 1;
			for(int i = 1;i<=a;i++){
				for(int j = 1;j<=b;j++){
					if(j!= 1)cout<<" ";
					if(i%2){
					cnt = (i-1)*b+j;
						if(cnt<=n)cout<<cnt;
						else cout<<0;
					}
					else{
						cnt = i*b-j+1;
						if(cnt<=n)cout<<cnt;
						else cout<<0;
					}
				}
				cout<<endl;
			}
		}
	}
}
