#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
vector<int> G[maxn];
int b;
int h;
int vis[maxn];
void init(int n){
    for(int i = 0;i<n;i++)G[i].clear();
}
void add_edge(int v,int u){
    G[v].push_back(u);
}
int main(){
   int n,m;
   while(cin>>n>>m){
       int s = 0;
        h = 0;b = 0;
        init(n);
        for(int i = 0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--;v--;
            add_edge(u,v);
            add_edge(v,u);
            s = u;
        }
        memset(vis,-1,sizeof(vis));
        queue<int >q;
        int yn = 0;
        for(int j = 0;j<n;j++){
            if(G[j].size()){
                if(vis[j] == -1){
                 q.push(j);
                    vis[j] = 0;

                    while(!q.empty()){
                        int x = q.front();q.pop();
                        if(vis[x])b++;
                        else h++;
                        for(int i = 0;i<G[x].size();i++){
                            int t = G[x][i];
                            if(vis[t] == vis[x]){
                                yn = 1;
                                break;
                            }
                            else if(vis[t] == -1){
                                vis[t] = 1 - vis[x];
                                q.push(t);
                            }
                        }
                        if(yn == 1)
                        break;
                    }


                }

            }
            if(yn == 1){

                break;
            }
        }


        if(yn == 1){
            cout<<"-1"<<endl;
        }
        else{
            cout<<h<<endl;
            for(int i = 0;i<n;i++){
                if(vis[i] == 0)cout<<i+1<<" ";
            }
            cout<<endl;
            cout<<b<<endl;
            for(int i = 0;i<n;i++){
                if(vis[i] == 1)cout<<i+1<<" ";
            }
            cout<<endl;
        }
   }

}







