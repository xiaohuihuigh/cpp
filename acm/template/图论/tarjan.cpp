#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int qltfk_num,index;
int dfn[maxn];
int low[maxn];
int vis[maxn];
int ins[maxn];
vector<int>G[maxn];
int belong[maxn];
stack<int >s;

void init(int n){
    qltfk_num = 0;
    index = 0;
    for (int i = 0;i<=n;i++){
        G[i].clear();
        ins[i] = 0;
    	dfn[i] = 0;
    	low[i] = 0;
    }
}
void tarjan(int u){
    dfn[u] = low[u] = index++;
    s.push(u);
    ins[u] = 1;
    for(int i = 0;i<G[u].size();i++){
        int v = G[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }else if(ins[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        qltfk_num++;
        int v;
        do{
            v = s.top();
            s.pop();
            ins[v] = 0;
        }while(v!=u);
    }
}
void scc(int n){
    for(int i = 1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
}
int main(){
    int n,m;
    while(cin>>n>>m&&(n||m)){
        int a,b;
        init(n);
        while(m--){
            cin>>a>>b;
            G[a].push_back(b);
        }
        scc(n);
        if(qltfk_num == 1)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
