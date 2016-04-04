#include<bits/stdc++.h>
using namespace std;
int f(int t){
	if(t<=100)
	return f(f(t+11));
	else return t-10;
}
int main(){
	int n;
	while(cin>>n&&n){
		cout<<"f91("<<n<<") = "<<f(n)<<endl;
	}
}
