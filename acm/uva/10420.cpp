#include<bits/stdc++.h>
using namespace std;
map<string,int> ma;
int main(){
	int n;
	cin>>n;
	string s = "\0";
	//
	for(int i = 0;i<n;i++){
		//getchar();
		while(s[0] == '\0'||s[0] == '\n')getline(cin,s);
		int l = s.size();
		char *str;str = (char*)malloc(200*sizeof(char));
		for(int i = 0;i<l;i++){
			if(s[i] ==' '){str[i] = '\0';break;}
			else str[i] = s[i];
		}
		string ss = str;
		//cout<<ss<<endl;
		ma[ss]++;
		s = "\0";
	}
	map<string,int>::iterator it = ma.begin();
	for(;it!=ma.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
}
