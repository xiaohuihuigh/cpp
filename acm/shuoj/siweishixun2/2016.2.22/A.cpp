#include<iostream>
using namespace std;
int main(){
	int a[5];
	int b[5];
	int c[5];
	int t[5];
	while(cin>>a[4]){
		for(int i = 0;i<3;i++)cin >>a[3-i];
		for(int i = 1;i<=4;i++)cin>>b[5-i];
		t[1] = (a[1]+b[1])/60;
		c[1] = (a[1]+b[1])%60;

		t[2] = (a[2]+b[2]+t[1])/60;
		c[2] = (a[2]+b[2]+t[1])%60;

		t[3] = (a[3]+b[3]+t[2])/24;
		c[3] = (a[3]+b[3]+t[2])%24;
		c[4] = (a[4]+b[4]+t[3]);
		for(int i = 1;i<=4;i++){
			if(i != 1)cout<<" ";
			cout<<c[5-i];
		}
		cout<<endl;
	}
	return 0;
}
