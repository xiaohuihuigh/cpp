#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int a[maxn][maxn];
int d[2*maxn][maxn];
int f[2*maxn];

int main(){
    int T;
    cin>>T;
    while(T--){
        int n1,n2;
        cin>>n1>>n2;
        memset(a,0,sizeof(a));
        for(int i = 1;i<=n1;i++)a[i][i] = 1;
        for(int i= 0;i<n2;i++){
            int x,y;
            cin>>x>>y;
            a[x][y] = a[y][x] = 1;
        }
        int n;
        cin>>n;
        memset(d,INF,sizeof(d));
        for(int i = 0;i<n;i++)cin>>f[i];
        for(int i = 1;i<=n1;i++)d[0][i] = (f[0] != i);
        for(int i = 1;i<n;i++){
            for(int k = 1;k<=n1;k++){
                for(int j = 1;j<=n1;j++){
                    if(a[k][j]){
                        d[i][k] = min(d[i][k],d[i-1][j]+(f[i]!=k));
                    }
                }
//                cout<<i<<" "<<k<<" "<<d[i][k]<<endl;
            }
        }
        int ans = INF;
        for(int i = 1;i<=n1;i++){
            ans = min(ans,d[n-1][i]);
        }
        cout<<ans<<endl;
    }
}
