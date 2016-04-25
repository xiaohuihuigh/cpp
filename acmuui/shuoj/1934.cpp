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
string reverse(string s)
{
 int c,j,i;
 for(i=0,j=s.length()-1;i<j;i++,j--)//完成倒置功能，不包括字符串结束符'/0'
 {
  c=s[i];
  s[i]=s[j];
  s[j]=c;
 }
 return s;
}
int dp[101][101];
int main()
{
    int n;cin>>n;
    string a,b;
    while(n--)
    {
        cin>>a;
        b=a;
        b = reverse(b);
        //cout<<a<<b;
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;
        REP(i,a.length())
        {
            REP(j,a.length())
            {
                if(a[i] == b[j]) {
                if(i > 0 && j > 0) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 1;
                }
                if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);

            }
        }
        /*REP(i,a.length())
        {
            REP(j,a.length())
            {
                cout<<dp[i][j]<<endl;
            }}*/
        int ans = 1+a.length()-1-dp[a.length()-1][a.length()-1];
        cout<<ans<<endl;

    }

}











/**************************************************************
    Problem: 1934
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1600 kb
****************************************************************/
