#include<bits/stdc++.h>
using namespace std;
int a[1010] ;
int main(){
	int m,n;
	while(cin>>m>>n){
		for(int i = 1;i<=m;i++)a[i] = 1;
		for(int i  = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				if(j%i== 0)a[j] = 1-a[j];
			}
		}
		int cnt = 0;
		for(int i  = 1;i<=m;i++){if(a[i] == 1)cnt++;}
		cout<<m-cnt<<endl;
}}

