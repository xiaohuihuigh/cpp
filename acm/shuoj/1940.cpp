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
const ll MOD = 1000000007;
ll fac[100005];
/*void extgcd(ll a,ll b,ll&d,ll &x,ll&y)
{
    if(!b){
        d = a;x = 1;y = 0;
    }else{
        extgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
ll inv (ll a ,ll k)
{
    ll d,x,y;
    extgcd(a,k,d,x,y);
    return d==1?(x+k)%k:-1;
} */
int fast_mod(ll n,ll m,ll k)
{
    ll cnt = 1;
    while(m)
    {
        if(m&1)cnt = cnt*n%k;//尽量不要写成出cnt *= n%k
        n = n*n%k;
        m>>=1;
    }
    return cnt;

}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll sum,a,b,k;
        scanf("%lld%lld%lld",&a,&b,&k);
        fac[0] = 1;
        REP2(i,1,a)
        fac[i] = ((fac[i-1]%k)*i)%k;
        /*REP(i,a+1)
        cout<<fac[i]<<endl;*/
       // sum = fac[a]*inv(fac[b]*fac[a-b]%k,k)%k;
        //sum = ((fac[a]*(fac[b]^(k-2)mod k)mod k) *fac[a-b]^(k-2)mod k)mod k;
        ll x,y;
        x = fast_mod(fac[b],k-2,k);y = fast_mod(fac[a-b],k-2,k);
        sum = ((fac[a]*x)%k*y)%k;
        printf("%lld\n",sum);
    }
    return 0;

}
/**************************************************************
    Problem: 1940
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:216 ms
    Memory:2340 kb
****************************************************************/
