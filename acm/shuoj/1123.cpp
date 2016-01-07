
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	n = 200000;
	cout<<0;
	for(long long i = 1;i<=200000;i++){
		int n = (long long)log10(i);
		n = (long long)pow(10,n+1);
		//cout<<i<<"  "<<n<<endl;;
		if(i*i%n == i)cout<<" "<<i;
	}
}
