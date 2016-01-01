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
//const int MAXN = 10010;
//#define INF 0x3FFFFFFF
int a[1005];
int main()
{
    int N,S,yen;
    while(~scanf("%d%d",&N,&S)){
        REP(i,N)
        {
            cin>>a[i];
        }
        yen = 0;
        sort(a,a+N);
        REP(i,N)
        {
            if(yen ==1) break;
            REP2(j,i+1,N-1)
            {
                if(yen ==1) break;
                int sum = a[i]+a[j];
                int l = j+1,r = N-1;
                int mid;
                while(l<r-1)
                {
                    mid = (l+r)/2;
                    if(sum+a[mid]>S)
                       {
                            r = mid;
                       }
                    else if(sum+a[mid]==S){yen = 1;break;}
                    else l = mid+1;
                }
                if(sum +a[l] == S)
                {
                    yen = 1;
                    break;
                }
            }
        }

        if(yen == 0)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}












/**************************************************************
    Problem: 1933
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:152 ms
    Memory:1568 kb
****************************************************************/
