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
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define M_PI 3.14159265358979323846
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define MAX_V 10101
#define maxn 567
#define lowbit(X) (X & (-X))
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;

int m,n;
int a[110][110];
bool yen = 0;
void dfs(int i,int j)
{
 	 if(i<0||i>=n||j<0||j>=m)return ;
	 if(a[i][j]==1)return ;//1
	if(i == n-1&&j == m-1)//2   1 2 Ë³Ðò²»ÄÜµßµ¹
	{yen = 1; return ;}
	a[i][j] = 1;
	dfs(i-1,j);
	dfs(i+1,j);
	dfs(i,j-1);
	dfs(i,j+1);

}

int main()
{
	while(cin>>n>>m)
	{
		yen = 0;
		 for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>a[i][j];
            }
        }
        dfs(0,0);
	if(yen)cout<<"Y"<<endl;
	else cout<<"N"<<endl;
	
	}
}

