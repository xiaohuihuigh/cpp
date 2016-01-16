/*#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
//求网络最小费用最大流,邻接阵形式
//返回最大流量,flow返回每条边的流量,netcost返回总费用
//传入网络节点数n,容量mat,单位费用cost,源点source,汇点sink
#define MAXN 250
#define MAXM 105
#define inf 1000000000
int mat[MAXN][MAXN];
int cost[MAXN][MAXN];
int flow[MAXN][MAXN];
struct ss
{
	int x,y;
}H[MAXM],M[MAXM];
int min_cost_max_flow(int n,int source,int sink,int& netcost){
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
	int N,m;
	while(cin>>N>>m&&(m||N)){
	getchar();char s;
	int k1,k2;
		for (int i = 1;i<=N;i++){
			for(int j = 1;j<=m;j++){
				cin>>s;
				if(s == 'H'){
					H[k1].x == i;
					H[k1++].y =j;
				}
				else if(s == 'M'){
					M[k2].x = i;
					M[k2++].y = j;
				}
			}
		}

		memset(mat,0x3f,sizeof(mat));
		memset(cost,0,sizeof(cost));
		int n = k1-1;
		for (int i = 0;i<2*n+1;i++)
		for (int j = 0;j<2*n+1;j++)
		cost[i][j]= inf;
		for(int i = 1;i<=n;i++){
			for (int j = n+1;j<=2*n+1;j++){
				cost[i][j] = abs(H[j - n].x -M[i].x) + abs(H[j - n].y - M[i].y);//每个人到每个房子的费用
				cost[j][i] = -cost[i][j];
				flow[i][j] = 1;
			}
			cost[i][0] = cost[0][i] = 0;
			flow[0][i]  = 1;
			cost[i + n][2 * n + 1] = cost[2 * n + 1][i + n] = 0;
			flow[i + n][2*n + 1] = 1;
		}


		int a,b,c;
		int netcost = 0;
		cout<<min_cost_max_flow(N,0,2*n+1,netcost);
		//cout<<netcost<<endl;
		//cout<<"reate<<endl"<<endl;
	}
}*/
#include <iostream>
#include <cstdlib>
#include<cstring>
#define max 105
#define Max  1000000000

using namespace std;
int flow[2*max][2*max],cost[2*max][2*max];
int map[max][max],pre[2*max],dis[2*max],minflow[2*max],mark[2*max];
char str[max][max];
int q[100000];
struct ss
{
   int x,y;
}house[max],man[max];

int spfa(int start,int end)
{
    int l, h, i, k;
    for(i=0;i<=end;i++)
    {
      dis[i]=Max;
      pre[i]=-1;mark[i]=0,minflow[i]=Max;
    }
    l = h = 0;
    q[l++] = start;
    dis[start]=0;
    mark[start]=1;
    while(l>h)
    {
        k = q[h++];
       //  puts("bug");
       //  cout<<end<<endl;
        mark[k]=0;
        for(i=0;i<=end;i++)
        {
           if(flow[k][i]&&dis[i]>dis[k]+cost[k][i])
           {
              dis[i]=dis[k]+cost[k][i];
              pre[i]=k;
              minflow[i]=min(minflow[k],flow[k][i]);
              if(!mark[i])
              {
                 mark[i]=1;
                 q[l++]=i;
              }
        }
    }
  }
   return dis[end]!=Max;
}
int maxflow_mincost(int start, int end)
{
     int i,x,ans=0;
    // cout<<end<<endl;
     while(spfa(start,end))
     {
         x = end;
         while(pre[x]!=-1)
         {
            flow[pre[x]][x] -= minflow[end];
            flow[x][pre[x]] += minflow[end];
            x=pre[x];
         }
         ans += dis[end];
         //cout<<ans<<endl;
        // puts("abc");
     }
     return ans;
}

int main()
{
    int N, M, i, j, k1,k2 ,n;
    while(scanf("%d%d",&N,&M)&&(N+M))
    {
        k1 = k2 = 1;
        memset(flow,0,sizeof(flow));
        for(int i=0;i<N;i++)
        {
          scanf("%s",str[i]);
          for(j=0;j<M;j++)
           {
               if(str[i][j]=='H')
               {
                  house[k1].x=i;
                  house[k1++].y=j;
               }
               else if(str[i][j]=='m')
               {
                  man[k2].x=i;
                  man[k2++].y=j;
               }
           }
        }
        n=k1-1;
       // cout<<n<<endl;
        for(i=0;i<2*n+1;i++)
         for(j=0;j<2*n+1;j++)
           cost[i][j]=Max;
        for(int i=1;i<=n;i++)
        {
         for(j=n+1;j<2*n+1;j++)
         {
             cost[i][j] = abs(house[j - n].x - man[i].x) + abs(house[j - n].y - man[i].y);//每个人到每个房子的费用
             cost[j][i] = -cost[i][j];//这点很重要，千万别忘了
             flow[i][j] = 1; //流量为 1
         }
       //  设置起点为0，终点为 2*n+1
          cost[i][0]=cost[0][i]=0;
          flow[0][i]=1;
          cost[i + n][2 * n + 1] = cost[2 * n + 1][i + n] = 0;
          flow[i + n][2*n + 1] = 1;
        }
         printf("%d\n", maxflow_mincost(0, 2*n + 1));
    }
   return 0;
}
