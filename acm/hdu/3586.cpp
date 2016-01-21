/**
不知道为什么叶子节点一定要用flag标记，不能直接通过判断G[i]的大小判断
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1005;
const int INF= 1000010;
int ans;
vector<pair<int ,int> >G[maxn];
int dp[maxn];
/*
int dfs(int u,int fa,int mi){
	dp[u] = 0;
	for(int i = 0;i<G[u].size();i++){
		//cout<<"dsf"<<endl;
		int v = G[u][i].first;
		if(v!=fa){
			dfs(v,u,mi);
			//int ni = min(mi,G[u][i].second,mi);
			if(G[u][i].second<=mi)dp[u]+=min(dp[v],G[u][i].second);
			else dp[u]+= dp[v];
		}
	}
	if(G[u].size() == 1){
		dp[u] = INF;
	}
	return ans;
}*/
int dfs(int u,int fa,int mi){
	dp[u] = 0;
	int flag = 0;
	for(int i = 0;i<G[u].size();i++){
		//cout<<"dsf"<<endl;
		int v = G[u][i].first;
		if(v!=fa){
			flag = 1;
			dfs(v,u,mi);
			//int ni = min(mi,G[u][i].second,mi);
			if(G[u][i].second<=mi)dp[u]+=min(dp[v],G[u][i].second);
			else dp[u]+= dp[v];
		}
	}
	if(!flag){
		dp[u] = INF;
	}
}
int main(){
	int n,m;
	while(cin>>n>>m&&(n||m)){
		ans = 0;
		int l =1,r = 0,mid;
		for(int i = 1;i<=n;i++)G[i].clear();
		for(int i = 0;i<n-1;i++){
			int a,b,c;
			cin>>a>>b>>c;
			r = max(r,c);
			G[a].push_back(make_pair(b,c));
			G[b].push_back(make_pair(a,c));
		}
		int ans = -1;
		while(l<=r){
			mid = (l+r)/2;
			dfs(1,-1,mid);
			if(dp[1]<=m){
				ans  =mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		 cout<<ans<<endl;
	}
}
/*
5 5
1 3 2
1 4 3
3 5 5
4 2 6
7 55
1 2 1
2 4 2
2 5 3
1 3 6
3 6 2
3 7 3
*/
