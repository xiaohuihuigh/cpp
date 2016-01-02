#include<bits/stdc++.h>
using namespace std;
char c[(1<<11)+1];
int n;
void dfs(int t){
	if(t<(1<<n)){
		dfs(2*t);
		dfs(2*t+1);
	}
	cout<<c[t];
}
int main(){
	cin>>n;getchar();
	char a;
	for(int i = 1<<n;i<(1<<(n+1));i++){
	cin>>a;
	if(a == '0')c[i] = 'B';
	if(a == '1')c[i] = 'I';
	}
	for(int i = (1<<n)-1;i>=1;i--)
		if(c[2*i] == 'I'&&c[2*i+1] == 'I')
			c[i] = 'I';
		else if(c[2*i] == 'B'&&c[2*i+1] == 'B')
			c[i] = 'B';
		else c[i] = 'F';
	dfs(1);
}
