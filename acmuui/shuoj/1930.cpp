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

int vis[100005];
int maps[100005];
int main()

{
    int T;
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(maps,0,sizeof(maps));
        int N,L;
        cin>>N>>L;
        REP(i,N)
        {
            cin>>maps[i];
            if(i<L)vis[maps[i]]++;
        }
        int yen = 0;
        REP(i,N-L+1)
        {
            REP(j,1001)
            {
            if(vis[j] >0)
            {
                if(yen == 0)
                    yen = 1;
                else cout<<" ";
            cout<<j;
            break;
            }
            }
            //if(vis[j] == 1)cout<<j<<endl;
            vis[maps[i]]--;
            vis[maps[L+i]]++;

        }
        cout<<endl;

    }
}









/**************************************************************
    Problem: 1930
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:312 ms
    Memory:2340 kb
****************************************************************/
