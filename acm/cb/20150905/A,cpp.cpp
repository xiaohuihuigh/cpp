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
#define INF 0x3FFFFFFFn
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
char s[101][110];
int mo[101];
int year[101];
int id[101];
int cmp(int x,int y){
	if(year[x]>year[y])return 1;
	else return 0;
	//return year[x] > year[y];
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		getchar();
		REP(i,n)id[i]  = i;
		REP(i,n){REP(j,105){
		    s[i][j] = getchar();
		    if(s[i][j] == '\n'){mo[i] = j;break;}
		}
		}
		CLR(year,0);
		REP(i,n)REP2(j,mo[i]-4,mo[i]-1)year[i]= year[i]*10+s[i][j]-'0';
		//REP(i,n)cout<<year[i]<<endl;//REP(j,mo[i]-5)cout<<s[i][j];
		sort(id,id+n,cmp);
		REP(i,n){REP(j,mo[id[i]]-5){/*if(s[id[i]][j] == ' ')cout<<"@@";*/cout<<s[id[i]][j];}cout<<endl;};
	}
	return 0;
}
