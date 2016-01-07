#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int a,b,m;
		cin>>a>>b>>m;int yn = 0;
		for(int i = m/a+1;i>=0;i--){
		//cout<<i;
			int sheng = m-a*i;
			if(sheng>=0&&sheng%b == 0){
			yn = 1;
			cout<<i<<" "<<sheng/b<<endl;
			break;}
		}
		if(yn == 0)cout<<"Impossible"<<endl;
	}
}

