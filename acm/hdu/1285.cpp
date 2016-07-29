
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int N = 505;
vector<int>g[N];//邻接表存储
int vis[N],topo[N],cnt;

bool dfs(int u)
{
    vis[u] = -1;//-1用来表示顶点u正在访问
    for(int i = g[u].size()-1 ; i >= 0 ; i --)
    {
        if(vis[g[u][i]] == -1)//表示这个点进入了两次，肯定出现了环
            return false;
        else if(vis[g[u][i]] == 0)
        {
            dfs(g[u][i]);
        }
    }
    vis[u] = 1;
    topo[cnt++] = u;//放到结果数组里，输出的时候记得倒序输出，（回溯的原因）
    return true;
}

bool toposort(int n)
{
    memset(vis,0,sizeof(vis));
    cnt = 0;
    for(int i  = n ; i >=1 ; i --)
    {
        if(!vis[i])
        {
            if(!dfs(i)) return false;//huan
        }
    }
    return true;
}
int main(){
    int m,n;
    while(cin>>m>>n){
    //建图
        for(int i = 0;i<n;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
        }
        for(int i = 1;i<=m;i++){
            sort(g[i].begin(),g[i].end());
        }
        //生成深度优先搜索树
        toposort(m);
        for(int i = m-1;i>=0;i--)i == m-1?cout<<topo[i]:cout<<" "<<topo[i];
        cout<<endl;
    }
}




