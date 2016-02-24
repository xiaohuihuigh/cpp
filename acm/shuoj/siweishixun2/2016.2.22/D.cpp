#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[15];
	while(cin>>a[9]){
		for(int i = 8;i>=1;i--){
			cin>>a[i];
		}
		a[10] = 0;
		a[0]  = 0;
		int k = 0;
		for(int i = 10;i>=1;i--){
			if(a[i ] != 0){
				k = 1;
				if(a[i] == 1&&i == 1)cout<<a[i];
				if(a[i]>1)cout<<a[i];
				if(i == 2)cout<<"x";
				if(i>2)cout<<"x^"<<i-1;
			}
			else{
				if(k == 0&&i == 1)cout<<a[i];
			}
			if(a[i-1]!= 0){
				if(a[i-1]>0){
					if(k != 0) cout<<" + ";

				}
				if(a[i-1]<0){
					if(k != 0)cout<<" - ";
					if(k ==0)cout<<"-";
					a[i-1] = -a[i-1];
				}
			}
			/*if(k != 0&&a[i-1]!=0)cout<<" + ";
			if(k == 0&&i == 1){
				if(k == 0)cout<<a[i];
				else{
					if(a[i]!= 0)cout<<a[i];
				}
			}
			if(a[i]!= 0&&i == 2){
			k = 1;
				if(a[i]!= 1)cout<<a[i];
				cout<<"x";
			}
			if(a[i]!= 0&&i != 1&&i!=2){
				k = 1;
				if(a[i]!= 1)cout<<a[i];
				cout<<"x^"<<i-1;
			}*/
		}
		cout<<endl;
	}
}
