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

ll a[11][11];
ll ret[11][11];
ll c[11][11];
int m,n;
void multi(ll d[11][11],ll b[11][11]){
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                       for(int k=0;k<n;k++){
                               c[i][j]+=d[i][k]*b[k][j];
                       }
               }
       }
}

int main(){
    int k,ca = 0;
    while(cin>>n>>k){
        REP(i,n)REP(j,n)cin>>a[i][j];
        REP(i,n)REP(j,n)if(i==j)ret[i][j] = 1;else ret[i][j] = 0;//初始化单位矩阵
            while(k)
            {
                if(k&1){
                    //ret = ret*a;
                    /**************/
                    multi(ret,a);
                    for(int i=0;i<n;i++){
                               for(int j=0;j<n;j++) {
                                    ret[i][j] = c[i][j];
                               }
                       }
                    /***************/
                }


                k>>=1;
               multi(a,a);
                    for(int i=0;i<n;i++){
                               for(int j=0;j<n;j++){
                                    a[i][j] = c[i][j];
                               }
                       }
                }
                if(ca++ != 0)cout<<endl;
    REP(i,n){REP(j,n){if(j != 0)cout<<" ";cout<<ret[i][j];}cout<<endl;}
    }

}







