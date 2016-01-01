#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10005];
int b[1000005];
int Next[10005];int n,m;
void getNext(int  a[]){
	int i = 0;int j = -1;
	Next[0] = -1;
		while(i<m){
		if(j == -1||a[i] == a[j]){
			Next[++i] = ++j;
		}
		else j = Next[j];
		}
}
int kmp(int a[],int b[]){
	int i = 0;int j = 0;
	getNext(a);
	while(i<n){
		if(j == -1||a[j]  == b[i]){
			i++;j++;
		}
		else {j = Next[j];}
		if(j == m){
			return i-m+1;
		}

	}return -1;
}
int main(){
	int T;
	cin>>T;
	while(T--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
		cin>>n>>m;
		for(int i = 0;i<n;i++){
			cin>>b[i];
		}
		for(int i = 0;i<m;i++){
			cin>>a[i];
		}
		cout<<kmp(a,b)<<endl;
	}
}
