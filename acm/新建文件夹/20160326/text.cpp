
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
long long num(long long x,long long l){
    while (x>=l)x/=10;
    return x;
}
ll f(ll x,int n)
{
	int num=0;
	ll y=x*x;
	while(y>0)
	{
		num++;
		y/=10;
	}
	num-=n;
	ll mod=1;
	if(num>0)while(num--)mod*=10;
	return (x*x)/mod;
}
int main(){int yn = 0;

	for(int j = 1;j<=9;j++){
	int n = j;ll l = 1;while(n--)l*=10;
	for(long long  i =0;i<l;i++){

	if(f(i,j)!=num(i*i,l)){cout<<i<<" "<<j<<" "<<f(i,j)<<" "<<num(i*i,l)<<endl;yn = 1;break;}
	}if(yn == 1)break;
	}
	cout<<"d"<<endl;
}
