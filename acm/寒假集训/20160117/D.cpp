#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100;
typedef long long ll;
ll a[maxn];
ll  wei[10] = {0};
ll  we(int n){
	memset(wei,0,sizeof(wei));
	int t = 0;int shu  = 0;
	while(n){
		wei[t++] = n&1;
		n>>=1;
		if(wei[t-1] == 1)shu++;
	}
	return shu;
}
int main(){
	ll n,m;
	while(cin>>n>>m){
		for(int i = 0;i<m;i++){
			cin>>a[i];
			if(a[i] == 0)i--,m--;
			}
			if(m == 0){cout<<0<<endl;continue;}
		/*sort(a,a+m);
		for(int i = 0;i<m;i++)
			for(int j = i;j<m;j++)
				if(a[j]%a[i] == 0)a[j] =a[i];
		int l = unique(a,a+m)-a;*/
		int l = m;
		ll cnt = (1<<l)-1;
		long long sum = 0;
		for(int i = 1;i<=cnt;i++){
		int yn = we(i);
			if(yn%2 ==1){
				ll num = 1;
				for(int j = 0; j<l;j++){
					if(wei[j] == 1)
					num*=a[j];
				}
				if(num == 0)continue;
				sum += (n-1)/num;
			}
			else{
				ll  num = 1;
				for(int j = 0; j<l;j++){
				//cout<<wei[j]<<" ";
					if(wei[j] == 1)
					num*=a[j];
				}
				//cout<<num<<endl;
				if(num == 0)continue;
				sum -= (n-1)/num;
			}
			//cout<<i<<" "<<sum<<endl;
		}
		cout<<sum<<endl;
	}
}
/*2147483647 20
*/

/*

#include<cstdio>
#include<algorithm>
typedef long long LL;
#define MAXN 110
using namespace std;
int n, m, ans;
int a[MAXN];
LL GCD(LL x, LL y) {
    return y ? GCD(y, x % y) : x;
}
LL LCM(LL x, LL y) {
    return x / GCD(x, y) * y;
}
LL Get(int x, int &cnt) {
    int i;
    LL res = 1;
    for (i = cnt = 0; i < m; i++) {
        if (x & (1 << i)) {
            cnt++;
            res = LCM(res, a[i]);
        }
    }
    return res;
}
int main() {
    int i, k;
    LL tmp;
    while (~scanf("%d%d", &n, &m)) {
        n--;
        k = m;
        for (ans = i = 0; i < m; i++) {
            scanf("%d", &a[i]);
            if (a[i] == 0)
                k = i;
        }
        if (k != m) {
            m--;
            swap(a[m], a[k]);
        }
        for (i = 1; i < (1 << m); i++) {
            tmp = Get(i, k);
            if (k & 1)
                ans += n / tmp;
            else
                ans -= n / tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}





*/
