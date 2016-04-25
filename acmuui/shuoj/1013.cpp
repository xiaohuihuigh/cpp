#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define M_PI 3.14159265358979323846
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define MAX_V 10101
//#define maxn 10
#define lowbit(X) (X & (-X))
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;

/************************************************
********************头文件**********************
************************************************/

 /* 这种方法是失败的，因为dfs时间复杂度为n！会超时
int n,m,X,Y;
int cnt = 0;
int dir[9][2]={{0,0},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
void dfs(int x,int y)
{
    if(x<0||x>n||y<0||y>m) return ;
    REP(i,10)
    if(x == X+dir[i][0]&&y == Y+dir[i][1])
        return ;
    if(x == n&&y == m)
    {
        cnt++;
    }
    dfs(x,y+1);dfs(x+1,y);
}
int main()
{
    cin>>n>>m>>X>>Y;
    dfs(0,0);
    cout<<cnt<<endl;
}

  */

ll n,m,X,Y;
ll dir[9][2]={{0,0},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
ll dp[28][28];
int main()
{
    cin>>n>>m>>X>>Y;
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    REP2(i,1,n+1)
    { REP2(j,1,m+1)
        {
            REP(k,9)
            {
                if(X+dir[k][0]+1>=0&&Y+dir[k][1]+1>=0)
                dp[X+dir[k][0]+1][Y+dir[k][1]+1] = 0;
            }
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
                dp[1][1] = 1;

        }
    }
    cout<<dp[n+1][m+1]<<endl;
}

/**************************************************************
    Problem: 1013
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1568 kb
****************************************************************/
