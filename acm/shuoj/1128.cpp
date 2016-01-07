#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(!(n&1))n--;
	cout<<(n+1)*(n+1)/4;
}
