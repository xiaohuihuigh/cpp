#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
vector<int>G[maxn];
int vis[maxn];
void dfs(int t){
    vis[t] = 1;
    for(int i = 0;i<G[t].size();i++){
        if(!vis[G[t][i]])dfs(G[t][i]);
    }
}
int main(){
    int n,m;
    while(cin>>n&&n){
            cin>>m;
        for(int i = 0;i<n;i++)G[i].clear();
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<m;i++){
            int a,b;
            cin>>a>>b;
            a--,b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int yn = -1;
        for(int i = 0;i<n;i++){
            int len = G[i].size();
            if(len%2)yn++;
            if(!vis[i]){dfs(i);yn+=1;}
        }
        if(yn == 0)cout<<1<<endl;
        else cout<<0<<endl;
    }
}
