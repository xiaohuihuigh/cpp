#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int head[maxn];//head[ i]表示edges中的edges[i]边的头节点
int cnt;
struct edge{
	int to,next,cost;
}edges[2*maxn];
void addedge(int x,int y,int c){
	edge &e = edges[cnt];
	e.to = y;
	e.next = head[x];
	e.cost = c;
	head[x]=cnt++;
}
int temp[maxn][3];//记录边值
int son[maxn];//重孩子
int val[maxn];//把边上的权值转移孩子点上的权值
int size[maxn];//子树大小
int id[maxn];//
int top[maxn];//重链顶端
int depth[maxn];//深度
int par[maxn];//父亲节点
int totw;
int bit[maxn];
void add(int i,int x){
	while(i<=n+10){
		bit[i]+=x;
		i+= lowbit(i);
	}
}
void dfs1(int u,int fa,int dep){
	par[u] = fa;
	depth[u] = dep;
	int Max = 0,pos = -1;
	size[u] = 1;
	for(int j = head[u];j!=-1;j=edges[j].next){//遍历含u边的所有边
		int v = edges[j].to,c = edges[j].cost;
		if(v == fa)continue;
		val[v] = c;//为什么把边的权值附给点？？导致树根没有权值就是转移的吧？？？！！！
		dfs1(v,u,dep+1);
		if(size[v]>Max){//记录最大的子树的大小，和节点
			Max = size[v];
			pos = v;
		}
		size[u]+= size[v];//求u的子树大小
	}
	son[u ] = pos;//重儿子节点
}
void dfs2(int u,int fa){
	id[u] =++totw;
	add(id[u],val[u]);
	if(son[u]!=-1){//先搜重儿子然后再dfs
		top[son[u]] = top[u];//向上转移top
		dfs2(son[u],u);
	}
	for(int j = head[u];j!=-1;j = edges[j].next){
		int v= edges[j].to,c = edges[j].cost;
		if(v == fa||v == son[u])continue;
		top[v ]= v;
		dfs2(v,u);
	}
}
int main(){
	int T,ca = 1;
	cin>>T;
	while(T--){
		memset(head,-1,sizeof(head));
		cnt  = 0;
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i = 0;i<n-1;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--;y--;
			temp[i][0] = x;
			temp[i][1] = y;
			temp[i][2] = 0;
			addedge(x,y,0);
			addedge(y,x,0);
		}
		for(int i = 0;i<n;i++){cout<<head[i]<<endl;}
		for(int i = 0;i<2*(n-1);i++){
			cout<<edges[i].next<<edges[i].to<<endl;
		}
		totw = val[0] = top[0] = 0;
		dfs1(0,-1,0);
		dfs2(0,-1);
		while(q--){
			getchar();
			string s;
			cin>>s;
			if(s[3] == '1'){
				int x,y,c;
				scanf("%d%d%d",&x,&y,&c);
			}
		}
	}
}
















