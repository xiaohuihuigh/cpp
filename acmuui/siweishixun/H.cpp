
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
char str[70000];
int num[20000];
map<int , bool>vis;
int zh(int j){
    int cnt = 0;
    int temp = 0;
    REP(i,j+1){
        if(str[i] == ' '||str[i]=='\n'){
        REP2(k,temp,i-1){num[cnt] = num[cnt]*10 + str[k]-48;}
       // cout<<num[cnt]<<" ";
        vis[num[cnt]] = 0;
        cnt++;
        temp = i+1;
        }
        if(str[i]=='\n')return cnt;
    }
}


int main(){
    while((str[0] = getchar())&&str[0]!=-1){
        int j = 1;
        while(str[j-1]!='\n'){
            str[j++] = getchar();
        }
       // REP(i,j)cout<<str[i];
        memset(num,0,sizeof(num));
        int cnt = zh(j);//cnt为转换为数字的个数(zh要兼顾map  cz

        REP(i,cnt)
        {
            if(vis[num[i]]==0)
            {
                if(i!= 0) cout<<" ";
                 vis[num[i]] = 1;
                cout<<num[i];
            }
        }
        cout<<endl;
    }
    return 0;
}





























