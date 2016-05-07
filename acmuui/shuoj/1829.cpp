
#include<bits/stdc++.h>
using namespace std;


long long gcd(long long x,long long  y){

    while(1){
        x>y?x %=y:y%=x;
	if(x == 0 )return y;
	if(y == 0 )return x;
    }
}

int main(){
	int T;
	cin>>T;
	while(T--){
		long long a,b,c,d;
		cin>>a>>b>>c;
		a<0?a = -a:a= a;
		b<0?b= -b:b= b;
		long long k = gcd(a,b);
		cout<<k;
		if(c%k != 0)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
} 
