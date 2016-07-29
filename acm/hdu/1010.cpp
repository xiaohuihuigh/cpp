
#include <bits/stdc++.h>
using namespace std;
char ma[9][9];        //地图最多不超过7行7列,又从(1,1)计算,所以开辟9,9
int n,m,t,di,dj;       //给定的三个量,以及终点位置
bool escape;           //标识逃生成功
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};  //分别表示左、右、下、上四个方向
void DFS(int si,int sj,int cnt)
{
    int i,temp;
    if (si>n || sj>m || si<=0 || sj<=0)   //越出边界便不搜索
        return;
    if (si==di && sj==dj && cnt==t)
    {
        escape=1;                   //时间正好的时候才能逃生
        return;
    }
    temp=abs(t-cnt)-(abs(di-si)+abs(dj-sj));     //计算当前到终点的最短路与还需要的时间差,若小于0则路径剪枝
    if (temp<0 || temp&1)           //temp如果是奇数的话也要剪枝
        return;
    for (i=0;i<4;i++)
    {
        if (ma[si+dir[i][0]][sj+dir[i][1]]!='X')
        {
            ma[si+dir[i][0]][sj+dir[i][1]]='X';  //把当前点刷为X
            DFS(si+dir[i][0],sj+dir[i][1],cnt+1); //搜索该点
            if (escape)
                return;
            ma[si+dir[i][0]][sj+dir[i][1]]='.';  //如果搜索不到退出来了,则重新把该点刷为'.'
        }
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    int i,j,si,sj,wall;
    while (cin>>n>>m>>t)
    {
        if (n==0 && m==0 && t==0)
        {
            break;
        }
        wall=0;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                cin>>ma[i][j];
                if (ma[i][j]=='S')
                {
                    si=i,sj=j;
                }
                else if (ma[i][j]=='D')
                {
                    di=i,dj=j;
                }
                else if (ma[i][j]=='X')
                {
                    wall++;
                }
            }
        }
        if (n*m-wall<=t)      //路径剪枝,当走完不含墙的迷宫都还不到T时间将不能逃生
        {
            cout<<"NO"<<endl;
            continue;
        }
        escape=0;
        ma[si][sj]='X';      //记得刷为'X'
        DFS(si,sj,0);
        if (escape)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}





