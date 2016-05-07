
/* ***********************************************
Author        :kuangbin
Created Time  :2013/8/21 18:28:50
File Name     :F:\2013ACM练习\专题学习\数学\莫比乌斯反演\SPOJ7001.cpp
这题就是求gcd(a,b,c) = 1    a,b,c <=N 的对数。
用莫比乌斯反演可以求解。

设g(n)为gcd(x,y,z)=n的个数，f(n)为n | g(i*n)的个数，那么有f(n)=sigma(n|d,g(d))，那么g(n)=sigma(n|d, mu(d/n)*f(d))，我们要求g(1)，则g(1)=sigma(n|d, mu(d)*f(d))，

因为f(d)=(n/d)*(n/d)*(n/d)，所以g(1)=sigma( mu(d)*(n/d)*(n/d)*(n/d) ).
************************************************ */

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
    int T,n;
    Moblus();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        long long ans = 3;
        for(int i = 1;i <= n;i++)
            ans += (long long)mu[i]*(n/i)*(n/i)*((n/i)+3);
        printf("%lld\n",ans);
    }
    return 0;
}
