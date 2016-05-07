
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 1000000;
bool check[MAXN+10];
int prime[MAXN+10];
int mu[MAXN+10];
int gcd(int a,int b) {
	int c;
	if(a ==0) return b;
   while(b!=0) c=b,b=a%b,a=c;
   return a;
}   
void Moblus()
{
    memset(check,false,sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= MAXN; i++)
    {
        if( !check[i] )
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,n,m;
    Moblus();
    //scanf("%d",&T);
    while(~scanf("%d%d",&n,&m))
    {
        //cout<<n<<m;
        long long ans = 0;
        long long an = 0;
        for(int i = 1;i <= n;i++){
        for(int j = 1;j<=n;j++)
                if(j%i == 0)
                an += (long long)mu[j/i]*(n/j)*(n/j);
        if(gcd(m,i)==1)
            ans += an;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
