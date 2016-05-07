#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int ca = 0;
	while(cin>>n){
		int cnt = 0;int t = n;
		while(t>0)
		{
			cnt += t/=5 ;
		}
		cout<<"Case "<<++ca<<":";
		cout<<n<<","<<cnt<<endl;
	}
	return 0;
}
