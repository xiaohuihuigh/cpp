#include <algorithm>
#include <cstdio>
using namespace std;
/*数组a,a+n排列
next_permutation(a,a+n)
prev_permutation(a,a+n)
*/
int mars[10005];
int main()
{
    int n,m;
     scanf("%d %d",&n,&m);
     for(int i=0;i<n;i++) scanf("%d",&mars[i]);
     for(int i=0;i<m;i++) next_permutation(mars,mars+n);
     for(int i=0;i<n;i++) {if(i != 0)printf(" ");printf("%d",mars[i]);}
    return 0;
}
