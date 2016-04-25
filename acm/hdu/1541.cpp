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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

#define lowbit(i) (i&(-i))
#define maxn 32010
int ans[maxn];
int bit[maxn],n;

int query(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=lowbit(i);
    }
    return s;
}

void add(int i,int x)
{
    while(i<=maxn-1)
    {
        bit[i]+=x;
        i+=lowbit(i);
    }
}


int main()
{
    while(scanf("%d",&n)!=EOF)
    {
         memset(ans,0,sizeof(ans));
        memset(bit,0,sizeof(bit));
        int x,y;int t;
        for(int i=0; i<n; i++)
        {
            int x,y;
           scanf("%d%d",&x,&y);x++;
           t = query(x);
           add(x,1);
           ans[t]++;
        }
        for(int i=0; i<n; i++)
             printf("%d\n",ans[i]);

    }
    return 0;
}
