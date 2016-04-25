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
	string a ;
	int T;
	cin>>T;
	getchar();
	while(T--){
        cin>>a;
        int j = 0,o = 0;
    int l = a.length();
    for(int i = 0;i<l;i++){
        if(i % 2 == 0|| i == 0){
            j += a[i] - '0';
        }
        else o+= a[i] - '0';
    }
        if((j - o)%11 == 0||(o - j) %11 == 0)
        {
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
	return 0;

   //printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);

}
