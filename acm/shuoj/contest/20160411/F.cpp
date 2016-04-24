#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[15];
	while(cin>>a[0]){
		int t = 0;
		int ans = 0;
		if(a[0]>300+t){cout<<-1<<endl;continue;}
		else {
			t = 300-a[0];
			while(t>=100){
				ans+=100;
				t-=100;
			}
		}
		int yn = 0;
		for(int i = 1;i<12;i++){
			cin>>a[i];
			if(a[i]>300+t){cout<<-1*(i+1)<<endl;yn = 1;}
			else {
				t = 300+t-a[i];
				while(t>=100){
					ans+=100;
					t-=100;
				}
			}
		}
		if(yn == 1)continue;
		else{
			cout<<ans*1.2+t<<endl;
		}

	}
}
