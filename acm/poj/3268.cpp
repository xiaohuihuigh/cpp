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
#define maxn 567
#define lowbit(X) (X & (-X))
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;


//#define INF 0x3FFFFFFF
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
//typedef PII pair<int,int>;
typedef  vector<PII>VII;

const int MAXN = 100010;
vector<PII> G[MAXN];
void add_edge(int u,int v,int d){
    G[u].push_back(make_pair(v,d));
}
void init(int n){
    for(int i=0;i<n;i++)G[i].clear();
}
int vis[MAXN];
int dis[MAXN];
int cnt[MAXN];
void spfa(int s,int n){
    for(int i = 0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int i = 0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
            if(dis[y] > dis[x] + d){
                dis[y] = dis[x] + d;
                if(!vis[y]){
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
}
int a[100001];
int b[100001];
int c[100001];
int d[100001];
int n,m,x;
int ant = 0;
void fun(int t)
{
	init(n);
	REP(i,m)
	{
		int u,v,d;
		u = a[i];
		v = b[i];
		d = c[i];
		u--,v--;
		if(t) add_edge(u,v,d);
		else add_edge(v,u,d);
	}
	spfa(x,n);
	REP(i,n)
	{
		d[i] += dis[i];
	}
}

int main()
{


	while(cin>>n>>m>>x)
	{
		x--;
		ant = 0;
		memset(d,0,n);
		REP(i,m)
		{
			cin>>a[i]>>b[i]>>c[i];
		}

		fun(0);
		fun(1);
		REP(i,n)
		ant = max(ant,d[i]);
		cout<<ant<<endl;
	}
	return 0;
	}
