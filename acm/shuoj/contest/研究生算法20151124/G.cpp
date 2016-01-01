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
#define maxn 10000000
#define lowbit(X) (X & (-X))
#include<ctime>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;


int a[102];
int b[102];
int c[102];


int main()
{
    int T;int suma,sumb;
    while(cin>>T){
            suma = 0;sumb = 0;
        for(int i = 0;i<T;i++){
            cin>>a[i]>>b[i];

            if(b[i] == -1)continue;
            else if(b[i]>=90)c[i] = 4;
            else if(b[i]>=80)c[i] = 3;
            else if(b[i]>=70)c[i] = 2;
            else if(b[i]>=60)c[i] = 1;
            else c[i] = 0;
            suma += a[i];
            sumb += a[i]*c[i];
        }
        printf("%.2lf\n",sumb*1.0/suma);
    }
    return 0;

}
