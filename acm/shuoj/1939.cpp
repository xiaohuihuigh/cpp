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
//const int MOD = 1e9+7;
int a[100005];
int b[100005];
int c[100005];
void fenjie1(int x){
    int k;
    for(k = x;k>1;k--){
        int j = k;int i;
        for(i = 2;i*i<=j;i++){
            while(j%i==0){
                a[i]++;
                j /=i;
            }
        }
        if(j!=1)
        a[j]++;
    }
}
void fenjie2(int x){
    int k;
    for(k = x;k>1;k--){
        int j = k;int i;
        for(i = 2;i*i<=j;i++){
            while(j%i==0){
                b[i]++;
                j /=i;
            }
        }
        if(j!=1)
        b[j]++;
    }
}
void fenjie3(int x){
    int k;
    for(k = x;k>1;k--){
        int j = k;int i;
        for(i = 2;i*i<=j;i++){
            while(j%i==0){
                c[i]++;
                j /=i;
            }
        }
        if(j!=1)
        c[j]++;
    }
}
ll fast_mod(int n,int m,int k){
    ll ans = 1;
    while(m){
        if(m&1)ans = ans * n % k;
        m>>=1;
        n = n*n%k;
    }
    return ans;
}
int main(){
    int T ;
    int m,n,k;
    ll answer;
    cin>>T;
    while(T--){
        cin>>m>>n>>k;
        answer = 1;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        fenjie1(m);
        fenjie2(n);
        fenjie3(m-n);
        REP(i,100005){
            a[i] = a[i] - b[i] - c[i];
            if(a[i]!= 0)
            answer = answer * fast_mod(i,a[i],k)%k;
            }
        cout<<answer<<endl;
    }
}




