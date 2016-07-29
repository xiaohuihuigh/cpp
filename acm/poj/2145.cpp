#include<bits/stdc++.h>
using namespace std;
#define N 310
#define INF 0x3f3f3f3f
#define INF 0x3FFFFFFF
typedef  pair<int,int> PII;
vector<PII> G[N];

struct People {
    int len, id, start, speed;
    double time;
}P[N];

int dis[N][N],d[N];
int n, m, k, zz;
bool vis[N];

void add_edge(int u,int v,int d){
    for(int i = 0;i<G[u].size();i++){
        if(G[u][i].first == v){
            int s = G[u][i].second;
            G[u][i].second = min(d,s);
            return;
        }
    }
    G[u].push_back(make_pair(v,d));
}

int cmp(People a, People b) {
    if (fabs(a.time - b.time) < 1e-7) {
        if (a.len == b.len) {
            return a.id > b.id;
        }
        else
            return a.len > b.len;
    }
    else
        return a.time < b.time;

}

void init() {
    for(int i=0;i<=n;i++)G[i].clear();
//    for (int i = 1; i <= n; i++)
//        dis[i][i] = 0;
}
void spfa(int s,int n){
    for(int i = 0;i<=n;i++)d[i] = (i == s ? 0 : INF);
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int i = 0;i<G[x].size();i++){
            int y = G[x][i].first;
            int s = G[x][i].second;
            if(d[y] > d[x] + s){
                d[y] = d[x] + s;
                if(!vis[y]){
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
}

int main() {
    while (scanf("%d%d%d", &n, &m, &k) != EOF) {
        init();
        int x, y, z;
        for (int i = 0; i < k; i++) {
            scanf("%d%d%d", &x, &y, &z);
            add_edge(y,x,z);
    //        dis[y][x] = min(dis[y][x], z);
        }
        scanf("%d", &zz);

        for (int i = 1; i <= m; i++) {
            scanf("%d", &P[i].start);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &P[i].speed);
        }

        spfa(zz,n);

        for (int i = 1; i <= m; i++) {
            if (d[P[i].start] == INF) {
                P[i].time = INF;
                P[i].len = INF;
                P[i].id = i;
            }
            else {
                P[i].time = d[P[i].start] * 1.0 / P[i].speed;
                P[i].len = d[P[i].start];
                P[i].id = i;
            }
        }
        sort(P + 1, P + m + 1, cmp);
        if (P[1].time == INF)
            printf("No one\n");
        else
            printf("%d\n", P[1].id);
        }
    return 0;
}
