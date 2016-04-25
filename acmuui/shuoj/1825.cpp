#include<bits/stdc++.h>
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
#define LOCAL
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
//const int MAXN = 10010;
int zhiyin[600000];
int fenjie(int n){
    int cnt = 0;
    for(int i = 2;i<= n;i++){
            int fn  = 0;
        while(n%i == 0){
            n = n/i;
            if(fn == 0){
                fn = 1;
               zhiyin[cnt++] = i;
            }
        }
    }
    if(n != 1)zhiyin[cnt++] = n;
    return cnt - 1;
}
int main(){
    /*
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif */
    /*int a[10];
    REP(i,10)scanf("%d",&a[i]);
    REP(i,10)printf("%d",a[i]);*/
	int n,m;
	int ca = 0;
	while(cin>>n>>m){
            int ans = 0;
	    memset(zhiyin, 0, sizeof(zhiyin));
            int cnt = fenjie(m);
        for(int i  = 1;i<=n;i++)
        {
            int yen = 0;
            for(int j = 0;j<=cnt;j++){
                if(i%zhiyin[j] == 0)yen = 1;
            }
            if(yen == 0) ans ++;
        }

        cout<<"Case "<<++ca<<": "<<ans<<endl;
	}
	return 0;

   //printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);

}
