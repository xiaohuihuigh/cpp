
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;
const int N=50010;

int n,m,Q;
int tim;

int num[N],siz[N],top[N],son[N];
int dep[N],tid[N],rank[N],fa[N];
int head[N],to[2*N],next[2*N],edge;

void Init()
{
    memset(head,-1,sizeof(head));
    memset(son,-1,sizeof(son));
    tim=0;
    edge=0;
}

void addedge(int u,int v)
{
    to[edge]=v,next[edge]=head[u],head[u]=edge++;
    to[edge]=u,next[edge]=head[v],head[v]=edge++;
}

//树链剖分部分
void dfs1(int u,int father,int d)
{
    dep[u]=d;
    fa[u]=father;
    siz[u]=1;
    for(int i=head[u];~i;i=next[i])
    {
        int v=to[i];
        if(v!=father)
        {
            dfs1(v,u,d+1);
            siz[u]+=siz[v];
            if(son[u]==-1||siz[v]>siz[son[u]])
                son[u]=v;
        }
    }
}

void dfs2(int u,int tp)
{
    top[u]=tp;
    tid[u]=++tim;
    rank[tid[u]]=u;
    if(son[u]==-1) return;
    dfs2(son[u],tp);
    for(int i=head[u];~i;i=next[i])
    {
        int v=to[i];
        if(v!=son[u]&&v!=fa[u])
            dfs2(v,v);
    }
}

//线段树部分
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

int sum[4*N],col[4*N];

void PushUP(int rt)
{
    sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
}

void PushDown(int rt,int m)
{
    if(col[rt])
    {
        col[rt<<1]+=col[rt];
        col[rt<<1|1]+=col[rt];
        sum[rt<<1]+=(m-(m>>1))*col[rt];
        sum[rt<<1|1]+=(m>>1)*col[rt];
        col[rt]=0;
    }
}

void Build(int l,int r,int rt)
{
    col[rt]=0;
    if(l==r)
    {
        sum[rt]=num[rank[l]];
        return;
    }
    int mid=(l+r)>>1;
    Build(lson);
    Build(rson);
    PushUP(rt);
}

void Update(int L,int R,int v,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        col[rt]+=v;
        sum[rt]+=v*(r-l+1);
        return;
    }
    PushDown(rt,r-l+1);
    int mid=(l+r)>>1;
    if(L<=mid)
        Update(L,R,v,lson);
    if(R>mid)
        Update(L,R,v,rson);
    PushUP(rt);
}

int Query(int l,int r,int rt,int val)
{
    if(l==r)
        return sum[rt];
    PushDown(rt,r-l+1);
    int mid=(l+r)>>1;
    int ret=0;
    if(val<=mid) ret=Query(lson,val);
    else         ret=Query(rson,val);
    PushUP(rt);
    return ret;
}

void Change(int x,int y,int val)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        Update(tid[top[x]],tid[x],val,1,n,1);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    Update(tid[x],tid[y],val,1,n,1);
}

int main()
{
    char oper[5];
    int a,b,c;
    while(~scanf("%d%d%d",&n,&m,&Q))
    {
        Init();
        for(int i=1;i<=n;i++)
           scanf("%d",&num[i]);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        dfs1(1,0,0);
        dfs2(1,1);
        Build(1,n,1);
        while(Q--)
        {
            scanf("%s",oper);
            if(oper[0]=='Q')
            {
                scanf("%d",&a);
                printf("%d\n",Query(1,n,1,tid[a]));
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                if(oper[0]=='D') c=-c;
                Change(a,b,c);
            }
        }
    }
    return 0;
}
