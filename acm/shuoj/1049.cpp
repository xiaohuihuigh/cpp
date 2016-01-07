#include<bits/stdc++.h>
using namespace std;

int yu[400];
int shu[400];
int yi[400];
int id[400];
int zong[400];
bool cmp(int x,int y){

	if(zong[x]>zong [y])return 1;
	if(zong[x] == zong[y]){
		if(yu[x]>yu[y])return 1;
		if(yu[x] == yu[y])
		if(x<y)return 1;
	}
	return 0;
}
int main(){
	int n;
	cin>> n;
	for(int i = 0;i<n;i++){
		cin>>yu[i]>>shu[i]>>yi[i];
		zong[i] = yu[i]+shu[i]+yi[i];
		id[i]  = i;
	}
	sort(id,id+n,cmp);
	for(int i = 0;i<5;i++)
	cout<<id[i]+1<<" "<<zong[id[i]]<<endl;
}
/*
6
90 67 80
87 66 91
78 89 98
88 99 77
67 89 64
78 89 98
*/
