#include<iostream>
#include<queue>
using namespace std;

const int maxn = 20 + 10;
const int INF = 0x3fffffff;
int map[maxn][maxn];
int point[4][2] = {0,1,0,-1,1,0,-1,0};
int temp[maxn*maxn][maxn*maxn];
int n;

bool judge(int x,int y) // 判断是否越界
{
    if(x>0 && x<=n && y>0 && y<=n)
    {
        return 1;
    }
    return 0;
}

int BFS(int s,int t)
{
    int flow = 0;
    while(1)
    {
        int pre[maxn*maxn];
        memset(pre,-1,sizeof(pre));
        int i;
        int min = INF;//找出最小流量
        queue<int> Q; //放进去的代表是第几个
        Q.push(s);
        int begin;
        while(!Q.empty())
        {
            begin = Q.front();
            Q.pop();
            for(i=1; i<=n*n+1; i++)
            {
                if(temp[begin][i] > 0 && pre[i] == -1)
                {
                    Q.push(i);
                    if(temp[begin][i] < min)
                    {
                        min = temp[begin][i];
                    }
                    pre[i] = begin;
                }
            }
            if(pre[t] != -1)
            {
                break;
            }
        }

        int u = t;
        if(pre[u] <= 0)
        {
            break;
        }

        while(u != s)  // 减去流量
        {
            temp[pre[u]][u] -= min;
            temp[u][pre[u]] += min;
            u = pre[u];
        }
        flow += min;
    }
    return flow;
}


int main()
{
    while(cin>>n)
    {
        memset(map,0,sizeof(map));
        memset(temp,0,sizeof(temp));
        int i;
        int j;
        int sum = 0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                cin>>map[i][j];
                sum += map[i][j];
            }
        }

        // 0作为源点  n*n+1作为汇点
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if( (i+j)%2 == 0 )
                {
                    temp[0][(i-1)*n+j] = map[i][j];
                }
                else
                {
                    temp[(i-1)*n+j][n*n+1] = map[i][j];
                }
            }
        }

        // 将与源点相连的点的相邻的值附上INF
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                for(int k=0; k<4; k++)
                {
                    int x = i + point[k][0];
                    int y = j + point[k][1];
                    if( judge(x,y) && (i+j) % 2 == 0 )
                    {
                        temp[(i-1)*n+j][(x-1)*n+y] = INF;   // (i-1)*n+j 代表的是第几个
                                                            // 123
                                                            // 456
                                                            // 789   的话7的话就是第7个
                    }
                }
            }
        }
        int s = 0;//源点
        int t = n*n+1;//汇点

        cout<<sum-BFS(s,t)<<endl;
    }
    return 0;
}
