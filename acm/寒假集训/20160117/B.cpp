//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
double a[17] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57};
int main(){
	double n;
	while(cin>>n){
		int t = 0;
		for(int i = 0;i<17;i++){
			int m = pow(n,1/a[i]);
			while(pow(m+1,a[i])<=n)m++;
			if(m<2)break;
			t+=(m-1);
		}
		t++;
		for(int i = 0;i<17;i++)
		for(int j = 0;j<17;j++){
		if(a[i]==a[j]||a[i]*a[j]>=60)break;
			int m = pow(n,1/(a[i]*a[j]));
			while(pow(m+1,a[i]*a[j])<=n)m++;
			if(m<2)break;
			t-=(m-1);
		}
		int m = pow(n,1/30);
			while(pow(m+1,30)<=n)m++;
			if(m>=2)
			t+=(m-1);
			m = pow(n,1/42);
			while(pow(m+1,42)<=n)m++;
			if(m>=2)
			t+=(m-1);
		cout<<t<<endl;
	}
}
