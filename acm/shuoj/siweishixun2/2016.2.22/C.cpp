#include<bits/stdc++.h>
using namespace std;
int main(){
	int m;
	cin>>m;
	while(m--){
		char s[10];
		scanf("%s",s);
		for(int i = 0;i<8;i++){
			if(s[i]>='a'&&s[i]<='z'){
				int t = s[i] - 'a';
				if(t>15)t--;
				if(t>21)t--;
				cout<<t/3+2;
			}
			else if(s[i]>='A'&&s[i]<='Z'){
				int t = s[i] - 'A';
				if(t>15)t--;
				if(t>21)t--;
				cout<<t/3+2;
			}
			else {
				cout<<s[i];
			}
			if(i == 3)cout<<"-";
		}
		cout<<endl;
	}
}
