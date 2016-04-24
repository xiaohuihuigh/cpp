#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {
	int c;
	if(a ==0) return b;
   while(b!=0) c=b,b=a%b,a=c;
   return a;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		while(a<b)b -= a;
		int t = gcd(a,b);
		cout<<a/t<<endl;
	}
}
