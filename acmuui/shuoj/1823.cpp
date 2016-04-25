#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int ca = 0;

	while(cin>>n>>m){
		cout<<"Case "<<++ca<<": ";
		if(n<m)
		{	cout<<"²»´æÔÚ"<<endl;continue;}
		for(int i = n;i>= m;i--){
			if(i%m == 0){
				cout<<i<<endl;
				break;
			}

		}
	}
	return 0;
}
