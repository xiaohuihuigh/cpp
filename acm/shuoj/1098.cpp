
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;

	for(int n = 100;n<1000;n++){
	int a,b,c,d;
	d = n;
	a  = n%10;
	n/=10;
	b = n%10;
	n/=10;
	c = n;//cout<<c<<b<<a<<pow(a,3)+pow(b,3)+pow(c,3)<<endl;
	if(d == pow(a,3)+pow(b,3)+pow(c,3))cout<<d<<endl;
	n= d;
	}
}
