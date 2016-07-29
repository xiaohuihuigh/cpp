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
typedef long long ll;
const int MAXN = 1010;
inline int input() { int x; scanf("%d", &x); return x;}
inline void print(char s = NULL,int t = 0){printf("%s%d ",s,t);}
int a[MAXN];
int main(){
    ios::sync_with_stdio(false);
    int n,k;
    while (cin>>n){
        int yn = 0;
        int cnt = 0;
    	for(int i = 0;i<n;i++){
            cin>>a[i];
            if(a[i] == 1)cnt++;
    	}
    	if(cnt == 1&&n == 1||n!= 1&&cnt == n-1)
    	cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

