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
#define XINF INT_ma
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))

#define INF 0x3FFFFFFF
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
//const int maN = 10010;

int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
bool lun(int m,int y)
{
	if(m<3)return 0;
	if(y%400 == 0||(y%100 != 0&&y%4 == 0))return 1;
	return 0;
}
int y,d,m,da;
int main(){
	int ca = 0;
	while(cin>>y>>m>>d){
		ca++;
		cout<<"Case "<< ca<<": ";
		
		if(m<10)cout<<"0"<<m<<"/";
		else cout<<m<<"/";
		if(d<10)cout<<"0"<<d<<"/";
		else cout<<d<<"/";
		if(y<10)cout<<"000"<<y<<", ";
		else if(y<100)cout<<"00"<<y<<", ";
		else if(y<1000)cout<<"0"<<y<<", ";
		else cout<<y<<", ";
		int da = 0;
		REP2(i,1,m-1)
		da += day[i];
		da += d+lun(m,y);
		cout<<da<<endl;
	}
}































