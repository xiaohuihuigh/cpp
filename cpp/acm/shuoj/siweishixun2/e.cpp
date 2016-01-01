#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 41000;
int vis[41000];
int Xor[41000];
vector<pair<int ,int > >V[maxn];

void dfs(int v){
    vis[v] = 1;
    for(int i = 0;i<V[v].size();i++){
        if(vis[V[v][i].first] == 0 ){
            Xor[V[v][i].first] = Xor[v]xor V[v][i].second;
            dfs(V[v][i].first);
        }
    }
}


int main(){
    int T;
    int ca = 0;
    scanf("%d",&T);
    while(T--){
    for(int i  = 0;i<maxn;i++)V[i].clear();
        int n,m;
        scanf("%d%d",&n,&m);
            for(int i = 0;i<n-1;i++){
                int u,v,w;
                scanf("%d%d%d",&u,&v,&w);
                V[u].push_back(make_pair(v,w));
                V[v].push_back(make_pair(u,w));
            }
            memset(vis,0,sizeof(vis));
            Xor[1] = 0;
       dfs(1);
       printf("Case %d:\n",++ca);
       for(int i = 0;i<m;i++){
        int a,b;
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        int t = Xor[a] xor Xor[b];
        //cout<<t<<endl;
        printf("%d\n",t);
       }
    }
}
