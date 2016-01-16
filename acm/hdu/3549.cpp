/*#include<iostream>
#include<cstring>
using namespace std;


//求网络最小费用最大流,邻接阵形式
//返回最大流量,flow返回每条边的流量,netcost返回总费用
//传入网络节点数n,容量mat,单位费用cost,源点source,汇点sink
#define MAXN 20
#define inf 1000000000
int mat[MAXN][MAXN];
int cost[MAXN][MAXN];
int flow[MAXN][MAXN];

int min_cost_max_flow(int n,int mat[][MAXN],int cost[][MAXN],int source,int sink,int flow[][MAXN],int& netcost){
	int pre[MAXN],min[MAXN],d[MAXN],i,j,t,tag;
	if (source==sink)
		return inf;
	for (i=0;i<n;i++)
	for (j=0;j<n;flow[i][j++]=0);
	for (netcost=0;;){
		for (i=0;i<n;i++)
			pre[i]=0,min[i]=inf;
		//通过bellman_ford寻找最短路，即最小费用可改进路
		for (pre[source]=source+1,min[source]=0,d[source]=inf,tag=1;tag;)
		for (tag=t=0;t<n;t++)
			if (d[t])
				for (i=0;i<n;i++)
					if (j=mat[t][i]-flow[t][i]&&min[t]+cost[t][i]<min[i])
						tag=1,min[i]=min[t]+cost[t][i],pre[i]=t+1,d[i]=d[t]<j?d[t]:j;
					else if (j=flow[i][t]&&min[t]<inf&&min[t]-cost[i][t]<min[i])
						tag=1,min[i]=min[t]-cost[i][t],pre[i]=-t-1,d[i]=d[t]<j?d[t]:j;
		if (!pre[sink])	break;
		for (netcost+=min[sink]*d[i=sink];i!=source;)
			if (pre[i]>0)
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}

	for (j=i=0;i<n;j+=flow[source][i++]);
	return j;
}

int main(){
	int T;
	cin>>T;
	for (int t = 1;t<=T;t++){
		int n,m;
		cin>>n>>m;
		int a,b,c;
		memset(mat,0,sizeof(mat));
		memset(cost,0,sizeof(cost));
		for(int i = 0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a--;b--;
			mat[a][b] += c;
		}
		int netcost = 0;
		cout<<"Case "<<t<<": "<<min_cost_max_flow(n,mat,cost,0,n-1,flow,netcost);
		//cout<<netcost<<endl;
		//cout<<"reate<<endl"<<endl;
	}
}*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
using namespace std;
const int maxn=20;
const int inf=0x3f3f3f3f;
int pre[maxn];   //保存前驱节点
bool vis[maxn];
int mp[maxn][maxn];//临接矩阵保存残留网络

int s,e;//s为源点，e为汇点
int n,m;//输入n个顶点，m条边

bool bfs()
{
    queue<int>q;
    memset(pre,0,sizeof(pre));
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int first=q.front();
        q.pop();
        if(first==e)
            return true;//找到一条增广路
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&mp[first][i])
            {
                q.push(i);
                pre[i]=first;
                vis[i]=1;
            }
        }
    }
    return false;
}

int max_flow()
{
    int ans=0;
    while(1)
    {
        if(!bfs())//找不到增广路
            return ans;
        int Min=inf;
        for(int i=e;i!=s;i=pre[i])//回溯找最小流量
            Min=min(Min,mp[pre[i]][i]);
        for(int i=e;i!=s;i=pre[i])
        {
            mp[pre[i]][i]-=Min;
            mp[i][pre[i]]+=Min;
        }
        ans+=Min;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    int u,v,c;
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&m);
        s=1,e=n;
        memset(mp,0,sizeof(mp));
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&c);
            mp[u][v]+=c;
        }
        printf("Case %d: %d\n",cas,max_flow());
    }
    return 0;
}
