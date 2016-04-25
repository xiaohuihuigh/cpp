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



int a[10050];


int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        REP(i,n)
        {
            cin>>a[i];
        }
    /*  REP(i,n)
        {
            cout<<a[i];
        }*/
        sort(a,a+n);
    /*  REP(i,n)
        {
            cout<<a[i];
        }*/

        double sum_x;
        double min = maxn;
        REP(j,n-k+1)
        {
            double sum = 0;
            REP2(h,j,j+k-1)
            {
                sum = sum +a[h];
             }
            // cout<<sum<<endl;
             sum_x = (double)sum /k;
             //cout<<sum_x<<endl;
             sum= 0;
             REP2(h,j,j+k-1)
             {
                 sum = sum +(a[h]-sum_x)*(a[h]-sum_x);
             }
             min = min<sum?min:sum;
             //cout<<"min"<<min<<endl;

        }
        printf("%0.2lf\n",min/k);

    }
}
