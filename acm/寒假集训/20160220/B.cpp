#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1005;
const int mod = 1e9+7;
int sum[maxn][maxn];
int a[maxn], b[maxn], c[maxn][maxn], n, m, dp[maxn][maxn];

inline void Init()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] = 0;
        for (int j = 1; j <= n; j++)
            dp[i][j] = c[i][j] = 0;
    }
    return;
}

inline int Lowbit(int x)
{
    return x & (- x);
}

inline void Update(int l, int pos, int key)
{
    while(pos <= n)
    {
        c[l][pos] = (c[l][pos] + key);
        while(c[l][pos]>=mod)
            c[l][pos] -= mod;
        pos = pos + Lowbit(pos);
    }
    return;
}

inline int Sum(int l, int pos)
{
    int temp = 0;
    while(pos)
    {
        temp = (temp + c[l][pos]);
        while(temp >= mod)temp -= mod;
        pos = pos - Lowbit(pos);
    }
    return temp;
}
int main(){
	int ca = 1;
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		Init();
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			b[i] = a[i];
		}
		sort(b+1,b+1+n);
		int l = unique(b+1,b+1+n)-b+1;
		for(int i = 1;i<=n;i++)
			a[i] = lower_bound(b+1,b+1+l,a[i])-b;
		int ans = 0;
		for(int i = 1;i<=n;i++){
		dp[i][1] = 1;
			for(int k = 2;k<=m&&k<=i;k++){
					dp[i][k] =Sum(k-1,a[i]-1);
			}
			for(int k = 1;k<=i;k++){
				Update(k,a[i],dp[i][k]);
			}
		}
		for(int i = 1;i<=n;i++){
			ans+=dp[i][m];
			while(ans>=mod) ans-=mod;
		}
		cout<<"Case #"<<ca++<<": ";
		cout<<ans<<endl;
	}
}




