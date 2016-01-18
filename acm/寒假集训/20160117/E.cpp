
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
    int T;
    Moblus();
    scanf("%d",&T);
    int ca  =1;
    while(T--)
    {
	int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k == 0) {printf("Case %d: 0\n",ca++);continue;}
        long long ans1 = 0,ans2 = 0;
        b = b/k;
        d = d/k;
        if(b>d)swap(b,d);
          for(int i = 1;i <= b;i++)
                ans1 += (long long)mu[i]*(b/i)*(b/i);
        for(int i = 1;i <= b;i++)
            ans2 += (long long)mu[i]*(b/i)*(d/i);
            ans2 -=ans1/2;
        printf("Case %d: %I64d\n",ca++,ans2);
    }
    return 0;
}
