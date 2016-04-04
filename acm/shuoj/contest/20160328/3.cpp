#include<bits/stdc++.h>
using namespace std;
string a;
int id[20];
int cmp(int x,int y)
{
	return (int)a[x]<(int)a[y];

}



int main(){

	while(cin>>a&&a!="THEEND"){
		string k;
		cin>>k;
		int la = a.length();
		int lk = k.length();
		int t = lk/la;
		for(int i = 0;i<la;i++)id[i] = i;
		sort(id,id+la,cmp);
		//for(int kk = 0;kk<la;kk++)cout<<id[kk];
		for(int kk = 0;kk<t;kk++)
		for(int i  = 0;i<la;i++){
			for(int j = 0;j<la;j++){
				if(id[j] == i){
					cout<<k[j*t+kk];
				}
			}
		}
		cout<<endl;
	}
}
