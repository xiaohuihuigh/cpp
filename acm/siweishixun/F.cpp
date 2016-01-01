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


int T;
int n;
double ma,mi,num,sum,ave;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		mi = 1000;
		ma = -1000;
		num = 0;sum = 0;ave = 0;
		REP(i,n)
		{
			cin>>num;
			if(mi>num){mi = num;}
			if(ma<num){ma = num;}
			sum += num;
		}
		printf("%.2lf,%.2lf,%.2lf\n",mi,ma,(sum - mi - ma)/(n-2));
	}
	return 0;
}






























