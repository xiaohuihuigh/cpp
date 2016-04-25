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
const ll MOD = 1000000007;
ll dp[1005][1005];

//计算C(m,n)对mod取模，每求一次就要调用一次;A,B是记忆化搜索的关键
ll com_num(int m,int n,int mod){
    if(dp[m][n]) return dp[m][n];////A
    if(m == n||n == 0)return 1;
    ll ret = (com_num(m-1,n-1,mod)+com_num(m-1,n,mod))%mod;
    dp[m][n] = ret;/////B
    return ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        dp[a][b] = com_num(a,b,MOD);
        printf("%lld\n",dp[a][b]);
    }
    return 0;

}
/**************************************************************
    Problem: 1938
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:128 ms
    Memory:8944 kb
****************************************************************/
