#include<bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF (0x3f3f3f3f)
#define MAXN (200)
#define eps (1e-10)
#define zero(a) (fabs(a)<eps)
#define sqr(a) ((a)*(a))
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define PF(X) push_front(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define PI  acos(-1.0)
#define test puts("OK");
#define lowbit(X) (X&(-X))
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef pair<int,int> PII;
typedef priority_queue<int,vector<int>,greater<int> > PQI;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second

int n,q;
VI G[MAXN];
int par[10][MAXN];
int depth[MAXN];

void dfs(int u,int d,int fa)//d表示深度，u表示节点，fa表示父亲节点
{
    par[0][u]=fa;//父亲节点
    depth[u]=d;
    REP(i,G[u].size())
    {
        int v=G[u][i];
        if(v==fa)
            continue;
        dfs(v,d+1,u);
    }
}

int go(int u,int step)
{
    int pos=u;
    for(int j=0;j<=9 && (1<<j)<=step;j++)
        if(step&(1<<j))
            pos=par[j][pos];
    return pos;
}

int lca(int u,int v)
{
    if(depth[u]<depth[v])
        swap(u,v);
    u=go(u,depth[u]-depth[v]);
    if(u==v)
        return u;
    for(int k=9;k>=0;k--)
    {
        if(par[k][u]!=par[k][v])
        {
            u=par[k][u];
            v=par[k][v];
        }
    }
    return  par[0][u];
}

int main()
{_
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,ca=1;
    scanf("%d",&T);
    while(T--)
    {
        CLR(G,0);CLR(par,-1);
        printf("Case %d:\n",ca++);
        int m;
        scanf("%d",&m);
        n=m+1;
        REP(i,m)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].PB(y);
            G[y].PB(x);
        }
        dfs(0,0,-1);
        for(int k=1;k<=8;k++)//par [i][h]  表示第i+1个祖先是h
            for(int i=0;i<n;i++)
                if(par[k-1][i]!=-1)
                    par[k][i]=par[k-1][par[k-1][i]];
                else
                    par[k][i]=-1;
        scanf("%d",&q);
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d%c",lca(x,y),q?' ':'\n');
        }
    }
    return 0;
}
