#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;
int a[maxn];
int  bfs(int t){
	int flag = 1;
	for(int i = 1;i<t;i++){
		if(a[i] - a[i-1] == 1 ){flag = 0;break;}
		if(a[i]>a[i-1]){
			int t = a[i]-1;
			a[i] = a[i-1]+1;
			a[i-1] = t;
			bfs(i);
		}
	}
	return flag;

}
int main(){
	int T;
	cin>>T;
	int ca = 1;
	while(T--){
		int n;
		cin>>n;
		for(int i = 0;i<n;i++)
		cin>>a[i];
		int flag = 1;
		for(int i =1;i<n;i++){
			if(a[i] - a[i-1] == 1 ){flag = 0;break;}
			if(a[i]>a[i-1]){
				int t = a[i]-1;
				a[i] = a[i-1]+1;
				a[i-1] = t;
				if(bfs(i) == 0){flag = 0;break;}
			}
		}
		if(flag ==0){cout<<"Impossible"<<endl;continue;}
		for(int i =0;i<n;i++){
			i == 0?cout<<a[i]:cout<<" "<<a[i];
		}
		cout<<endl;


	}
}
