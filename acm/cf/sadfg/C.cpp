#include<bits/stdc++.h>
using namespace std;
map<string,map<string ,int> >ma;
map<string ,int>mas;
string s[100000];
int main(){
	int n;
	while(cin>>n){
	int st = 0;int yn = 1;
		for(int i = 0;i<n;i++){
			string str; getline(cin,str);
			int len = str.size();
			for(int i= 1;i<len;i++){
				if(str[i] == str[i-1]&&str[i] =='.'){yn = 0;break;}
			}
			if(yn == 0)continue;
			string ss;int cnt = 0;
			for(int i = 0;i<len;i++){
				if((i!= len-1&&str[i] == '/'&&str[i-1]!='/'&&str[i+1]!= '/')||(i == len-1&&str[i] == '/'&&str[i-1]!='/')){
					s[st++] = ss;

				}
				else{
					ss[cnt++] = str[i];
				}

			}
		}
	}
}
