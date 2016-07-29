/***************************
//并查集终极版本
//带两种优化
****************************/
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define pb(X) push_back(X)

const int maxn = 1e6+5;
int p[maxn];
int pa[maxn];
int ra[maxn];
int ans[maxn];
int kk[maxn];
vector<int > G[maxn];
vector<int > Gx[maxn];
map<int,int> ma;
void init(int n){
    for(int i = 0;i<=n;i++){
        pa[i] = i;
        ra[i] = 0;
    }
}
int find(int x){
    if(pa[x]!=x)pa[x] = find(pa[x]);
    return pa[x];
}
int unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return 0;
    if(ra[x] < ra[y]){
        pa[x] = y;
    }else{
        pa[y] = x;
        if(ra[x] == ra[y])ra[x]++;
    }
    return 1;
}
bool same(int x,int y){
    return find(x) == find(y);
}

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        ma.clear();
        init(n+1);
        for(int i= 0;i<=n;i++)G[i].clear(),Gx[i].clear();
        for(int i = 1;i<=n;i++)cin>>p[i];
        for(int i = 0;i<m;i++){
            int x,y;
            cin>>x>>y;
            unite(x,y);
        }
//        for(int i = 1;i<=n;i++){
//            cout<<find(i)<<endl;
//        }
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            if(find(i) == i){
                ma[i] = cnt;
                G[cnt].pb(i);
                Gx[cnt++].pb(p[i]);
            }
        }
        for(int i = 1;i<=n;i++){
            if(find(i) == i){;
            }
            else{
                G[ma[find(i)]].pb(i);
                Gx[ma[find(i)]].pb(p[i]);
            }
        }

//        for(int i = 0;i<cnt;i++){
//            sort(G[i].begin(),G[i].end());
//            for(int j = 0;j<G[i].size();j++){
//                cout<<G[i][j]<<" ";
//            }
//            cout<<endl;
//        }

        for(int i = 0;i<cnt;i++){
            sort(G[i].begin(),G[i].end());
            sort(Gx[i].begin(),Gx[i].end());
            int l = G[i].size();
            for(int j = 0;j<l;j++){

                ans[G[i][j]] = Gx[i][l - 1 - j];
            }
        }
        for(int i = 1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
}
