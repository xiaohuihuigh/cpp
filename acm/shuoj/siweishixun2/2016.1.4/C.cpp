#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[5];
int main(){
	int n;
	while(cin>>n){
		for(int i = 0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		if(n == 1){cout<<a[0]<<endl;continue;}
		int t = n;
		b[0] = a[0];
		b[1] = a[1];
		int m = 1;
		long long sum = 0;
		int cnt = 0;
		while(t>0&&n>0){
		if(n>2&&t>2){
			if(m == 1){
				sum += b[1]+b[0];
				t=t-1;
				m = 0;
			}
			else{
				sum+= a[n-1]+b[1];
				t-=2;
				m++;
			}
		}
		else{
		if(m == 1){
				sum += b[1];
				m = 0;
				t-=2;
			}
			else {
				sum+= a[n-1];
				n-=2;
				t-=2;
				m++;
			}
		}
		cout<<sum<<endl;
		}
		cout<<sum<<endl;
	/*	for(int i = 1;i<=cnt;i++){
		if(c[i][1] != 0)
			cout<<c[i][0]<<" "<<c[i][1]<<endl;
			else  cout<<c[i][0]<<endl;
		}*/
	}
}
