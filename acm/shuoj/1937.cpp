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
const int MOD = 1e9+7;
ll factorial(ll a)
{
    ll fac = 1,cnt = a;
    for(int i = 1;i<cnt;i++){
        fac = fac*a;
        a -=1;
    }
    return fac;

}
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        ll a,b;
        cin>>a>>b;
        ll fa,fb,fc;
        fa = factorial(a);
        fb = factorial(b);
        fc = factorial(a - b);
        //cout<<fa<<" "<<fb<<" "<<fc<<endl;
        cout<<(fa/fb/fc)%MOD<<endl;
    }
    return 0;
}























/**************************************************************
    Problem: 1937
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:60 ms
    Memory:1560 kb
****************************************************************/
