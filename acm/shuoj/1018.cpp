//本体要点： 抽象成图，单向图，找出图中每个点是否相连可以用变相的flody
//高精度类模板bign
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
//#define maxn 10 
#define lowbit(X) (X & (-X)) 
#include<ctime> 
using namespace std; 
typedef long long ll; 
typedef pair<int,int>PII; 
typedef pair<PII,int>PPI; 
  
/************************************************
********************头文件**********************
************************************************/ 
 int W,H;
 char maps[81][1001];
 int cnt[81][1001];
 int dfs(int x,int y)
 {
	 if(maps[x][y] == '.'||x<0||y<0||x>=W||y>=H) return 0;
	 map[x][y] = '.';
	 return 1+dfs(i-1,j)+dfs(i+1,j)+dfs(i,j-1)+dfs(i,j+1);
 }
int main()
{
	while(cin>>W>>H)
	{
		REP(i,W)
		REP(j,H)
		{
			cin>>maps[i][j];
		}
		int cnt = 0,count = 0;
		REP(i,W)
		REP(j,H)
		{
			cnt = dfs(i,j);
			count = max(count,cnt);
		}
		cout<<count<<endl;
	}		
}  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

