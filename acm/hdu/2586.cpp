#include<iostream>
using namespace std;
const int N = 40010;
const int M = 25;
int dp[2*N][M];//dfs遍历后的序列
bool vis[N];
int first[2*N];
struct edge{
	int to,next;
}edges[2*N];
int tot = 0,head[N],cnt = 0;
void addedge(int a,int b,int c){
	edge &e = edges[cnt];
	e.to = b;e.next = head[a];
	e.cost = c;
	head[a] = cnt++;
}

void dfs(int u,int dep){
	vis[u] = true;ver[++tot] = u;//ver 节点
	first[u] = tot;R[tot] = dep;

	}
int main(){
	int T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i = 1;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			add_edge(a,b,c);
			add_edge(b,a,c);
		}
		while(m--){
			int a,b;
			cin>>a>>b;
			lca(a,b);
		}
	}
}
