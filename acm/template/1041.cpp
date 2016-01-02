#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >V1;
vector<pair<int,int> > V2;

bool cmp(pair<int,int>x,pair<int,int>y){
	if(x.first == y.first){
		if(x.second>x.second)return 1;
	}
	if(x.first<y.first)return 1;
	return 0;
}
int main(){
	int l,m;
	cin>>l>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		V1.push_back(make_pair(a,b));
	}
	sort(V1.begin(),V1.end(),cmp);
	//for(int i = 0;i<V1.size();i++)cout<<V1[i].first<<" "<<V1[i].second<<endl;
	pair<int,int> P1,P2;
	V2.push_back(V1[0]);int t = 0;
	for(int i = 1;i<m;i++){
		P2 = V2[t];
		P1 = V1[i];
		if(P1.first<=P2.second){
			if(P1.second>P2.second)V2[t].second = P1.second;
		}
		else{
			V2.push_back(P1);
			t++;
		}
	}
	//for(int i = 0;i<V2.size();i++)cout<<V2[i].first<<" "<<V2[i].second<<endl;
	for(int i = 0;i<V2.size();i++){
		P2 = V2[i];
		l=l-(P2.second-P2.first+1);
	//	cout<<l+1<<endl;
	}
	cout<<l+1<<endl;
}
