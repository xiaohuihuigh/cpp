#include<bits/stdc++.h>
using namespace std;
const int maxn = 50;
int g[maxn][maxn];
int vis[maxn][maxn];
int fa[maxn][maxn];
int dist[maxn][maxn];
int last_dir[maxn][maxn];
int q[maxn];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};//xia,you,shang,zuo
int n,m;
void bfs(int x,int y){
    int front  = 0,rear = 0,d,u;
    u = x*m+y;
    vis[x][y] == 1;fa[x][y] = u;dist[x][y] = 0;
    q[rear++] = u;
    cout<<x<<" "<<y<<" "<<fa[x][y]<<endl;
    while(front<rear){
        u = q[front++];
        x = u/m;
        y = u%m;
        for(d = 0;d<4;d++){
            int nx = x+dir[d][0];
            int ny = y+dir[d][1];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&vis[nx][ny]==-1&&g[nx][ny] == 0){
                int v = nx*m+ny;
                q[rear++] = v;
                vis[nx][ny] = 1;
                fa[nx][ny] = u;
                last_dir[nx][ny] = d;
                dist[nx][ny] = dist[x][y]+1;
                cout<<nx<<" "<<ny<<" "<<dist[nx][ny]<<" "<<fa[nx][ny]<<endl;
            }
        }
    }
}
/*
void display_fa(int x,int y){
    if(x*m+y == fa[x][y]){
        //cout<<x<<" "<<y<<endl;
        return ;
    }
    int tx = fa[x][y]/m;
    int ty = fa[x][y]%m;

    cout<<tx<<" "<<ty<<endl;
    if(tx>=0&&tx<m&&ty>=0&&ty<n)
    display_fa(tx,ty);
    return ;
}*/
void display_fa(int x,int y){
    int tx = fa[x][y]/m;
    int ty = fa[x][y]%m;
    if(tx != x||ty != y){
        display_fa(tx,ty);
        cout<<tx<<" "<<ty<<endl;
    }
}
int main(){

    while(cin>>m>>n){
        memset(g,-1,sizeof(g));
        memset(vis,-1,sizeof(vis));
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)g[i][j] = 0;
        int a,b;
        int k;
        cin>>k;
        while(k--){cin>>a>>b;g[a][b] = 1;}
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        bfs(x1,y1);
       for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<fa[i][j]/m<<" "<<fa[i][j]%m<<endl;
            }
            cout<<endl;
        }
        //display_fa(x2,y2);
    }
}
/*
5 6 7
0 2
1 1
2 1
2 3
2 4
3 1
4 3

0 0
0 4


*/

