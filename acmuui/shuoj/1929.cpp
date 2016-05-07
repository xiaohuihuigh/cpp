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
#define maxn 10
#define lowbit(X) (X & (-X))
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;

/************************************************
********************头文�?*********************
************************************************/
//int G[101][101]; //G[i][j]表示i比j最少高G[i][j]
int G[101][101];
vector<pair<pair<int,int> ,int> > V;
int T[101]; //T[i]表示i最少的分数
int P[101]; //过度T[]
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,q;
        cin>>n>>p>>q;
        V.clear();
        memset(T,0,sizeof(T)); /////初始�?
        memset(P,0,sizeof(P)); ///
        memset(G,0,sizeof(G));
        int a,b,x;
        REP(i,p)
        {
            cin>>a>>x;
            a--;                //编号�?开�?
            T[a] = x;           //记录分数
        }
        REP(i,q)
        {
            cin>>a>>b>>x;
            a--;b--;
            G[a][b] = max(x,G[a][b]); //因为标明可能有多组数据就必然有多组数�?始终保持取到较大的差�?
            //V.PB(MP(MP(a,b),G[a][b]));
        }
        REP(i,n)
        REP(j,n)
        {
            if(G[i][j] != 0) V.PB(MP(MP(i,j),G[i][j]));
        }

        REP(i,min(n,q)) //取n,q中的小值就可以完成全部更新
        {
            REP(s,V.size())
            {
                int g = V[s].second;
                int j = V[s].first.first;
                int k = V[s].first.second;
                if(g != 0&&T[j]-T[k]<g)
                {
                   // cout<<j<<" "<<k<<" "<<T[j];
                    if(P[j]<T[k]+g)P[j] = T[k] + g;
                  //  cout<<" "<<P[j]<<endl;
                }
            }
            /*REP(j,n)
            REP(k,n) //循环遍历每个条件
            {
                int g;
                g = G[j][k]; //g >0 题中已注�?
                if(g != 0&&T[j]-T[k]<g) //将需要更新分数的进行记录，如果直接更新会出错
                {
                    //cout<<j<<" "<<k<<" "<<T[j];
                    if(P[j]<T[k]+g)P[j] = T[k] + g;
                    //cout<<" "<<P[j]<<endl;
                }

            } */
            REP(i,n) //将记录的分数更新
                {
                    if(P[i] != 0)
                        T[i] = P[i];

                }
        }
        cout<<T[0]<<endl; //输出第一个的分数
    }
    return 0;
}

/**************************************************************
    Problem: 1929
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:32 ms
    Memory:1604 kb
****************************************************************/
