#include<bits/stdc++.h>
using namespace std;
int ss[8][2] = {2,1,2,-1,-2,-1,-2,1,1,2,-1,2,-1,-2,1,-2};
int main(){
	int T;
	cin>>T;

	while(T--){
		char s1,s2;
		getchar();
		cin>>s1>>s2;
		int ans = 0;
		for(int i = 0;i<8;i++){
			int a = (int)s1;
			int b = (int)s2;
			int ax = a + ss[i][0];
			int bx = b+ss[i][1];
			if(ax>='a'&&ax<='h'&&bx>='1'&&bx<='8')
				ans++;
		}
		cout<<ans<<endl;
	}
}
