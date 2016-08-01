#include<bits/stdc++.h>
using namespace std;
const int maxn = 30000;
int f[maxn];
int main(){
	int n;
	while(cin>>n){
		memset(f,0,sizeof(f));
		f[0] = 1;
		for(int i =2 ;i<=n;i++){
			int c = 0;
			for(int j = 0;j<maxn;j++){
				int s =f[j]*i+c;
				f[j] = s%10000;
				c = s/10000;
			}
		}
		int j;
		for(j = maxn;j>=0;j--)if(f[j])break;
		for(int i = j;i>=0;i--)cout<<f[i];
		cout<<endl;
	}
}
