


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+10;
typedef long long LL;

LL F[MAXN],f[MAXN];
int pri[MAXN],pri_num;
int mu[MAXN];//莫比乌斯函数值
int vis[MAXN],a[MAXN];

void mobius(int N)  //筛法求莫比乌斯函数
{
    pri_num = 0;//素数个数
    memset(vis, 0, sizeof(vis));
    vis[1] = mu[1] = 1;
    for(int i = 2; i <=N; i++)
    {
        if(!vis[i])
        {
            pri[pri_num++] = i;
            mu[i] = -1;
        }
        for(int j=0; j<pri_num && i*pri[j]<N ;j++)
        {
            vis[i*pri[j]]=1;//标记非素数
            //eg:i=3,i%2,mu[3*2]=-mu[3]=1;----;i=6,i%5,mu[6*5]=-mu[6]=-1;
            if(i%pri[j])mu[i*pri[j]] = -mu[i];
            else
            {
                mu[i*pri[j]] = 0;
                break;
            }

        }
    }
}

inline LL get(int x)
{
    return (LL)((x*(x-1))/2);
}

int main()
{
    mobius(100005);
    int n;
    while(~scanf("%d",&n))
    {
        memset(F,0,sizeof(F));
        memset(f,0,sizeof(f));
        int mmax = -1;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            f[a[i]]++;
            mmax = max(mmax, a[i]);
        }
        //求F[N]
        for(int i=1;i<=mmax;i++)
        {
            for(int j=i;j<=mmax;j+= i)
            {
                F[i]+=f[j];//个数
            }
            F[i]=get(F[i]);//C(N,2),表示对数；保证了gcd(a,b);(a<b)
        }

        LL ans = 0;
        for(int i=1; i<=mmax; i++)
            ans+=F[i]*mu[i];
        printf("%lld\n", ans);
    }
    return 0;
}
