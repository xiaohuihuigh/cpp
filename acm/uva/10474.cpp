#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int a[maxn];
int b[maxn];
int main(){
	int n,m;
	int ca = 1;
	while(cin>>n>>m&&(n||m)){
		int c;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i = 0;i<n;i++){cin>>c;a[c]++;}
		int sum = 0;
		for(int i = 0;i<10001;i++){i ==0?b[i] = a[i]:b[i]=b[i-1]+a[i];}
		cout<<"CASE# "<<ca++<<":"<<endl;
		for(int i = 0;i<m;i++){
			cin>>c;
			if(a[c] == 0){cout<<c<<" not found"<<endl;}
			else
			cout<<c<<" found at "<<b[c-1]+1<<endl;
		}
	}
}
