#include<bits/stdc++.h>
using namespace std;
#define XINF ll_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep1(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define fors(i,s) for(auto i = (s).begin();i!=(s).end();i++)
#define all(s) (s).begin(),(s).end()
#define clr(A,X) memset(A,X,sizeof(A))
#define it iterator
#define lson l,m,((rt)<<1)
#define rson m+1,r,((rt)<<1|1)
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  prllf("%lld\n",x)
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const int maxn = 55;

int dir[8][2] = {{1,0},{1,1},{-1,0},{-1,-1},{0,1},{0,-1},{1,-1},{-1,1}};
char s[maxn][maxn],word[maxn];
void f(int n,int m,int len){
    rep1(i,1,n){
        rep1(j,1,m){
        	if(s[i][j] == word[0]){
                rep(k,8){
//                    cout<<i<<j<<endl;
                    int x = i;
                    int y = j;
                    int d = 0;
                    while(word[d]&&word[d] == s[x][y]){
                        x+=dir[k][0];
                        y+=dir[k][1];
//                        cout<<x<<" "<<y<<word[d+2]<<s[x][y]<<endl;
                        d++;
                    }
//                    if(d)cout<<i<<" "<<j<<" "<<k<<" "<<d<<endl;
                    if(d == len){
                        cout<<i<<" "<<j<<endl;return ;
                    }
                }
        	}
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        memset(s,'#',sizeof(s));
        rep1(i,1,n){
            rep1(j,1,m){
            	cin>>s[i][j];
            	s[i][j] = toupper(s[i][j]);
            }
        }
        int k;
        cin>>k;
        rep(i,k){
            cin>>word;
            int j;
            for(j = 0;word[j]!= '\0';j++)
                word[j] = toupper(word[j]);
                f(n,m,j);

        }
        if(T!=0)cout<<endl;
    }


}
