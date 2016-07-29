#include<bits/stdc++.h>
using namespace std;
const int maxn = 500;
vector<int> G[maxn];
int yc[maxn];
int ycn[maxn];
int c[maxn];
void init(int n){
    for(int i = 0;i<n;i++)G[i].clear();
}
int main(){
    int n,k;
    while(cin>>n>>k){
        memset(yc,0,sizeof(yc));
        init(n);
        for(int i = 0;i<n;i++){
            int s;
            cin>>s;
            yc[s]++;
            if(yc[s] == 1)
            G[s].push_back(s);
        }
        int yn = 1;
        while(1){
            yn = 1;
            for(int i = 1;i<=k;i++){
                if(yc[i]!= 0)
                for(int j = i;j<=k;j++){
                    if(yc[j] != 0){
                        for(int a = 1;a<=k;a++)ycn[a] = yc[a];
                        int cn = 0;
                        for(int ii = 0;ii<G[i].size();ii++){
                            ycn[G[i][ii]]--;
                            if(ycn[G[i][ii]] < 0){
                                cn = 1;
                                break;
                            }
                        }

                        for(int jj = 0;jj<G[j].size();jj++){
                            ycn[G[j][jj]]--;
                            if(ycn[G[j][jj]] < 0){
                                cn = 1;
                                break;
                            }
                        }
                        if(!cn){
                            int t = i+j;
                            yc[t] = -1;
                            for(int ii = 0;ii<G[i].size();ii++){
                                G[t].push_back(G[i][ii]);
                            }
                            for(int jj = 0;jj<G[j].size();jj++){
                                G[t].push_back(G[j][jj]);
                            }
                        }
                    }
                }
            }
            if(yn == 1)break;
        }
        int ans = 0;
        yc[0] = 1;
        for(int i = 0;i<=k;i++){
            if(yc[i]!= 0)ans++;
        }
        cout<<ans<<endl;
        for(int i = 0;i<=k;i++){
            if(yc[i]!= 0)cout<<i<<" ";
        }
        cout<<endl;

    }
}








