#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100;

int n,q;
vector<int > G[MAXN];
int par[10][MAXN];
int depth[MAXN];
void dfs(int u,int d ,int fa){
	par[0][u] = fa;
	depth[u] = d;
	for(int i = 0;i<G[u].size();i++){
		int v  = G[u][i];
		if(v == fa)continue;
		dfs(v,d+1,u);
	}
}
int go(int u,int step){
	int pos  = u;
	for(int j = 0;j<=9&&(1<<j)<=step;j++)
		if(step&(1<<j))pos = par[j][pos];
	return pos;
}
int lca(int u,int v){
	if(depth[u]<depth[v])swap(u,v);
	u = go(u,depth[u]-depth[v]);
	if(u == v)return u;
	for(int k = 9;k>=0;k--){
		if(par[k][u]!= par[k][v]){
			u = par[k][u];
			v=  par[k][v];
		}
	}
	return par[0][u];
}
int main(){
	int T,ca = 1;
	scanf("%d",&T);
	while(T--){
		memset(G,0,sizeof(G));
		memset(par,-1,sizeof(par));
		printf("Case %d:\n",ca++);
		int m;
		scanf("%d",&m);
		n = m+1;
		for(int i= 0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(0,0,-1);
		for(int k = 1;k<=8;k++)
		for(int i = 0;i<n;i++){
			if(par[k-1][i]!=-1)
				par[k][i] = par[k-1][par[k-1][i]];
			else
			par[k][i] = -1;
		}
		scanf("%d",&q);
		while(q--){
			int x ,y;
			scanf("%d%d",&x,&y);
			printf("%d%c",lca(x,y),q?' ':'\n');
		}
	}
	return 0;
}











