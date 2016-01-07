#include<bits/stdc++.h>
using namespace std;
int a[30010];
int main(){
	int w;
	cin>>w;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int cnt = 0;
	for(int i = n-1,j = 0;i>=j;i--){
		if(a[i]+a[j]<=w)j++;
		cnt++;
	}
	cout<<cnt<<endl;
}
