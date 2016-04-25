#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
vector<ll> path[120][120];

ll c[120][120];
ll d[120][120];
ll max_load(int x,int y){
    if(path[x][y].empty())
        return d[x][y];
    for(int i = 0;i<path[x][y].size();i++){
        ll ans = path[x][y][i];
        return max(d[x][y],max_load(ans,y)+max_load(x,ans));
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        for(int i = 0;i<120;i++)
        for(int j = 0;j<120;j++)
        path[i][j].clear();
        int m,n,s,e;
        cin>>n>>m>>s>>e;
        int u,v,a,b;

        for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            c[i][j] = 2000;
        for(int i = 0;i<n;i++)c[i][i] = 0;
        for(int i = 0;i<m;i++){
            cin>>u>>v>>a>>b;
            u--;v--;
            c[u][v] = a;c[v][u] = a;
            d[u][v] = b;d[v][u] = b;
        }
        for (int k =0 ; k< n; k++)
        {
            for (int i = 0; i< n; i++){
			for (int j = 0; j< n; j++)
				if (c[i][j] > c[i][k] + c[k][j])
				{
					c[i][j] = c[i][k]+c[k][j];
					path[i][j].clear();
					path[i][j].push_back(k);
				}

				else if (c[i][j] == c[i][k] + c[k][j] && k!= i &&k !=j)
					path[i][j].push_back(k);
            }
        }
         cout<<c[s-1][e-1]<<" ";
         cout<<max_load(s-1,e-1)<<endl;
    }
    return 0;
}
