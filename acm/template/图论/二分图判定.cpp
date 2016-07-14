#include<bits/stdc++.h>
#define maxn 305
using namespace std;

vector<int> G[maxn];
int vis[maxn];//三种状态，-1未访问，0,1分别为一直颜色
bool dfs(int u)
{
    int visit = vis[u];
    for(int i=0;i<3;i++)
    {
        int v = G[u][i];
        if(vis[v] == -1){
            vis[v] = visit^1;
            if(!dfs(v))
            return false;
        }
        else if(vis[v] == visit)return false;

    }
    return true;
}

int main()
{
    int n,x,y;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
        G[i].clear();
        memset(vis,-1,sizeof(vis));
        while(cin>>x>>y&&(x||y))
        {
            x--;y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int yn = 1;
        for(int i = 0;i<n;i++){
            if (vis[i] == -1){
                vis[i] = 1;
                if(!dfs(i)){
                    yn = 0;
                    break;
                }
            }
        }
        if(yn) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
/*
6
1 2
1 3
1 4
2 5
3 5
4 5
2 6
3 6
4 6
0 0

*/
