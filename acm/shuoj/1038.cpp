#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
vector<pair<pair<int ,int >,int > > V;
int p[25][25];
bool cmp(pair<pair<int ,int >,int >x,pair<pair<int ,int >,int >y){
	if(x.second<y.second)return 0;
	return 1;
}
int main(){
	int m,n,k;
	while(cin>>m>>n>>k){
	V.clear();
		for(int i = 1;i<=m;i++)
		for(int j = 1;j<=n;j++){
		cin>>p[i][j];
		if(p[i][j]!=0)
		V.push_back(make_pair(make_pair(i,j),p[i][j]));
		}
		sort(V.begin(),V.end(),cmp);
		int t = 0;int ans = 0;
		k = k - V[0].first.first-1;
		while(t<V.size()&&k>=V[t].first.first){
			ans += V[t].second;
			k = k-abs(V[t].first.first-V[t+1].first.first)-abs(V[t].first.second-V[t+1].first.second)-1;
			t++;
		}
		cout<<ans<<endl;
	}
}
/*
6 7 4
0 0 0 0 0 0 0
0 0 0 0 0  0 0
0 0 0 0 0 0 0
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0

*/































