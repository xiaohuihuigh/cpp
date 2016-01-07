#include<bits/stdc++.h>
using namespace std;
char al[30];
char a[30];
int main(){
	int s,t,w;
	cin>>s>>t>>w;
	al[1]  ='a';getchar();
	for(int i = 2;i<=26;i++)al[i] = al[i-1]+1;
	//for(int i = 2;i<=26;i++)cout<<al[i];
	for(int i = 1;i<=w;i++)cin>>a[i];
	//for(int i = 1;i<=w;i++)cout<<a[i];
	int nm= 5;
	while(nm--){
	//cout<<"aaa"<<endl;
		for(int i = w;i>=1;i--){
		//cout<<"bbb"<<endl;
		//cout<<al[t]<<" "<<a[i]<<endl;;
		//cout<<w<<" "<<i<<"w-i"<<w-i<<"al - a"<<al[w]- a[i]<<endl;
			if(w-i<al[t]-a[i]){
			//cout<<"ccc"<<endl;
				a[i]++;
				for(int j = i+1;j<=w;j++)
					a[j] = a[j-1]+1;
				for(int j = 1;j<=w;j++)cout<<a[j];
				break;
				cout<<endl;
			}
		}
	}
}
