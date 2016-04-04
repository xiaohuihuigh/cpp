#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	while(cin>>n>>m&&n&&m){
		int a;
		int yn = 0;
		for(int i = 0;i<n;i++){
			if(i != 0)cout<<" ";
			cin>>a;
			if(yn == 0&&m<a){
				cout<<m<<" ";yn = 1;
			}
			cout<<a;
		}
		cout<<endl;
	}
}
