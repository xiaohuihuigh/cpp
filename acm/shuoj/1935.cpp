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
typedef int ll;

typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
//const int MAXN = 10010;
//#define INF 0x3FFFFFFF
/*************************************
 **************头文件*****************
 *************************************/
ll a[100005],b[100005];
ll c[100005],d;
//map <int,int> c;
ll ans;
void Merge(ll a[],ll low,ll mid,ll high)
{
//  ll *b = new ll[high+1];///// 不能动态分配内存，会TME
    ll i = low,j = mid+1,k = low;
    while(i<=mid&&j<=high)
        if(a[i]<=a[j])
            b[k++] = a[i++];
        else
        {
            d = c[k];
            c[k] = c[j];
            c[k] = c[k]+mid+1-i;
            b[k++] = a[j++];
            //c[b[k-1]] = c[b[k-1]]+mid+1-i;

            ans=max(ans,c[k-1]);        //这里将a[j]赋给b[k]中间跳过了mid+1-i个数
        }                       //这些数就是a[j]共有多少个逆序对
    while(i<=mid)
        b[k++] = a[i++];
    while(j<=high)
        b[k++] = a[j++];
    for(i = low;i<=high;i++)
        a[i] =b[i];
}
void MergeSort(ll a[],ll n)//两路归并
{
    ll len = 1,i;
    while(len < n){
        i = 0;
        while(i+2*len<=n){
            Merge(a,i,i+len-1,i+2*len-1);
            i+=2*len;
        }
        if(i+len<n)
            Merge(a,i,i+len-1,n-1);
        len*=2;
    }
}
int main()
{
    ll n;
    while(scanf("%d",&n)!=EOF)
    {
        //c.clear();
        memset(c,0,sizeof(c));
       // memset(d,0,sizeof(d));
        REP(i,n)
        {
            scanf("%d",&a[i]);
            //c[a[i]] = 0;
        }
      /*  REP(i,n)
        {
            cout<<c[i];
            //c[a[i]] = 0;
        }*/
        ans = 0;
        MergeSort(a,n);
        //map<int,int>::iterator it;
       /* for(it=c.begin();it!=c.end();++it)
        {
            ans = max(ans,it->second);
        }   */          //调用归并函数进行排序
       /*  REP(i,n)
        {
            cout<<c[i];
            //c[a[i]] = 0;
        }*/
        printf("%d\n",ans);             //直接输出答案
    }
    return 0;
}













/**************************************************************
    Problem: 1935
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:520 ms
    Memory:2732 kb
****************************************************************/
