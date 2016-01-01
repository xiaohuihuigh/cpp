
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
#define INF 0x3F3F3F3F
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
//#define INF 0x3FFFFFFF
/*************************************
 **************头文件*****************
 *************************************/

ll a[500005],b[500005];
ll ans;
void Merge(ll a[],ll low,ll mid,ll high)
{
//	ll *b = new ll[high+1];///// 不能动态分配内存
	ll i = low,j = mid+1,k = low;
	while(i<=mid&&j<=high)
		if(a[i]<=a[j])
		{
			b[k++] = a[i++];
		}

		else
		{
			b[k++] = a[j++];
			ans+=mid+1-i;
		}
		while(i<=mid)
			b[k++] = a[i++];
		while(j<=high)
			b[k++] = a[j++];
		for(i = low;i<=high;i++)
			a[i] =b[i];
	//	ans +=high-low+1;
	//	delete []b;

}
void MergeSort(ll a[],ll n)
{
	ll len = 1,i;
	while(len < n)
	{
		i = 0;
		while(i+2*len<=n)
		{
			Merge(a,i,i+len-1,i+2*len-1);
			i+=2*len;
		}
		if(i+len<n)
		{
			Merge(a,i,i+len-1,n-1);
		}
		len*=2;
	}

}


int main()
{
	ll n;
	int ca = 0;
	while(cin>>n)
	{
		REP(i,n)
		{
			cin>>a[i];
		}
		ans = 0;
		MergeSort(a,n);
		/*REP(i,n)
		{
			cout<<a[i];
		}*/
		cout<<"Case "<<++ca<<":"<<endl;
		cout<<ans<<endl;
	}
	return 0;
}


