/*问题描述：给定正整数m, n，其中n<=107，求使得gcd(x,y)为质数的(x,y)的个数，1<=x<=m， 1<=y<=n 。*/
    #include <iostream>
    #include <string.h>
    #include <stdio.h>

    using namespace std;
    typedef long long LL;
    const int N = 10000005;

    bool vis[N];
    int p[N];
    int cnt;
    int g[N],u[N],sum[N];

    void Init()
    {
        memset(vis,0,sizeof(vis));
        mu[1] = 1;
        cnt = 0;
        for(int i=2; i<N; i++)
        {
            if(!vis[i])
            {
                prime[cnt++] = i;
                mu[i] = -1;
            }
            for(int j=0; j<cnt&&i*prime[j]<N; j++)
            {
                vis[i*prime[j]] = 1;
                if(i%prime[j]) mu[i*prime[j]] = -mu[i];
                else
                {
                    mu[i*prime[j]] = 0;
                    break;
                }
            }
        }
    }
    int main()
    {
        Init();
        int T;
        scanf("%d",&T);
        while(T--)
        {
            LL n,m;
            cin>>n>>m;
            if(n > m) swap(n,m);
            LL ans = 0;
            for(int i=1,last;i<=n;i=last+1)
            {
                last = min(n/(n/i),m/(m/i));
                ans += (n/i)*(m/i)*(sum[last]-sum[i-1]);
            }
            cout<<ans<<endl;
        }
        return 0;
    }
