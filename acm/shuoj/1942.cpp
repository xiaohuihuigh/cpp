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
//b = (b-a)%(b+a) = (b-a+a+b)%(b+a) = (b+b)%(a+b);a = a+a = (a+a)%(a+b)//Ö´ÐÐÒ»´Î
//b = b*2^k%(a+b);a = a*2^k%(a+b)
ll a,b;
int k;
ll fast_mod(ll n,ll m,ll kk){
    ll ret=1;
    while(m){
        if(m&1)ret = ret*n%kk;
        n=n*n%kk;
        m>>=1;
    }
    return ret;
}
int main(){
	while(cin>>a>>b>>k){
		ll c = a+b;
		b = b*fast_mod(2,k,c)%(c);
		//b = b*(int)pow(2.0,k*1.0)%(a+b);
		a = a*fast_mod(2,k,c)%(c);
		//cout<<b<<endl;
		//a = a*(int)pow(2.0,k*1.0)%(a+b);
		//cout<<a<<endl;
		cout<<((a>b)?b:a)<<endl;
	}
	return 0;
}

