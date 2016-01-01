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
ll a[101];
ll b[101];
int T;
bool yns[101];
int main(){
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        REP(i,n)cin>>a[i];
        CLR(yns,0);
         ll min1  = INF,min2 = INF;int t;
        REP(i,n)
        {
            for(int j = 2;j*j<=a[i];j++)
            {//int ta = a[i];
                while(a[i]%j==0&&a[i])
                {
                    a[i]/=j;
                    if(min1>j) min1 = j;
                    else if(min2>j)min2  = j;
                    else break;
                }
            }
            if(min1>a[i]&&a[i] != 1) min1 = a[i];
            else if(min2>a[i]&&a[i] != 1)min2  = a[i];
            //cout<<"i"<<i<<min1<<" "<<min2<<endl;
            }
                /*{
                if(a[i]%j == 0) {b[i] = j; yns[i] = 1;break;}
            }
            if(yns[i] == 0&&b[i] != 1)b[i] = a[i];
            if(b[i] == 1)b[i] = INF;
        }

        REP(i,n) {if(min1>b[i]){min1 = b[i];t = i;}}
        b[t] = INF;
        REP(i,n) {if(min2>b[i]){min2 = b[i];}}*/
        if(min1 == INF||min2 == INF)cout<<"-1"<<endl;
        else cout<<min1*min2<<endl;
    }
}










