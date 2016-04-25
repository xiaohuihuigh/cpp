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
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;


string a;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        cin>>a;
        int t = a.size();
        int j = 1,i = 0;
        int yen1 = 0,yen2 = 0;
        while (i+j<t)
        {
            if(a[i] != a[t-j])
            {
            //  cout<<a[i]<<" "<<a[t-j]<<endl;
                if(a[i+1] == a[t-j])
                {
                    yen1++;
                    i++;
                }

                else yen1 = 2;

            }
            if(yen1 >1)
            break;
            i++;
            j++;

        }
         j = 1;i = 0;
        while (i+j<t)
        {
            if(a[i] != a[t-j])
            {
            //  cout<<a[i]<<" "<<a[t-j]<<endl;
                 if(a[i] == a[t-j-1])
                {
                    yen2++;
                    j++;
                }

                else yen1 = 2;

            }
            if(yen2 >1)
            break;
            i++;
            j++;

        }
    /*  */
        if(yen1<=1||yen2<=1)
        cout<<"YES\n";
        else
        cout<<"NO\n";
        a.clear();
    }
    return 0;


}
