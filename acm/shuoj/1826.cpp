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
int main(){
    /*
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif */
    /*int a[10];
    REP(i,10)scanf("%d",&a[i]);
    REP(i,10)printf("%d",a[i]);*/
	int n;int ca = 0;

	while(cin>>n){
        int yn = 0;
		cout<<"Case "<<++ca<<": "<<n<<" is ";
        if (n == 1) yn = 1;
		for(long long  i = 2;i*i<=n;i++){
			if(n%i == 0){yn = 1;break;}
		}
		if(yn == 1)cout<<"not a prime."<<endl;
		else cout<<"a prime."<<endl;

	}
	return 0;

   //printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);

}
