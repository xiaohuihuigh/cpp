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
const int MAXN = 1010;
inline int input() { int x; scanf("%d", &x); return x;}
inline void print(char s = NULL,int t = 0){printf("%s%d ",s,t);}
vector<int> G[MAXN];
int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        for (int i = 0;i<n;i++){
        	int k;
        	cin>>k;
        	for (int j = 0;j<k;j++){
        		int p;
        		cin>>p;
        		G[i].PB(p);
        	}
        }
        for(int i = 0;i<n;i++){
            sort(G[i].begin(),G[i].end());
        }
        int ans = 0;
        for (int i = 0;i<n;i++){
        	int l = (i+n-1)%n;
        	int r = (i+n+1)%n;
        	int ls = 0,rs = 0;
        	int le = 0,re = 0;
        	for(int j = 0;j<G[i].size()-1;j++){
//        	    cout<<"j "<<j<<endl;
                int s = G[i][j];
                int e = G[i][j+1];

                while(ls<G[l].size()&&G[l][ls]<s)ls++;
                le = ls;
                while(le<G[l].size()&&G[l][le]<e)le++;
                int lans = le - ls;
//                cout<<le<<" "<<ls<<endl;
                ls = le;

                while(rs<G[r].size()&&G[r][rs]<s)rs++;
                re = rs;
                while(re<G[r].size()&&G[r][re]<e)re++;
                int rans = re - rs;
//                cout<<re<<" "<<rs<<endl;
                rs = re;
//                cout<<rans<<" "<<lans<<endl;
                if(rans!= lans)ans++;

        	}
//        	cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
}

