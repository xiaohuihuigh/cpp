#include<bits/stdc++.h>
using namespace std;
using namespace std;
#define INF 0x3FFFFFFF
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define lson l,m,rt<<1
#define rson m+1,r,tr<<1|1
typedef pair<int,int>PII;
typedef vector<PII>VII;
const int MAXN = 100010;
inline int input() { int x; scanf("%d", &x); return x;}
inline void print(char s = NULL,int t = 0){printf("%s%d ",s,t);}
int main(){
    ios::sync_with_stdio(false);
    int a,b;
    char d,e;
    string c;
    int ans = 0;
    while(cin>>a>>d>>b>>e>>c){
        int t;
        if(d == '-')
            t = a-b;
        if(d == '+')
            t = a+b;
        if(c == "?")continue;
        string c1;
        int cnt = 0;
        while(t){
            int s = t%10;
            t/=10;
            c1[cnt++] = s + '0';
        }
        int yn = 0;
        for(int i = 0;i<cnt;i++){
            if(c[i] != c1[cnt-1-i]){
                yn = 1;
                break;
            }

        }
        if(!yn)ans++;
    }
    cout<<ans<<endl;
}
