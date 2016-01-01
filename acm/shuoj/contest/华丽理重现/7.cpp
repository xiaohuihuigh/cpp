
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
const int MAXN = 1005;
int pa[MAXN];
int ra[MAXN];
int nlz[1005];
int jz[1005];
set<int > S;
long long fi[50];
void fib(){
    fi[0] = 1;fi[1] = 1;
    int i = 1;
    while(fi[i]<1000000000){
        fi[i+1] = fi[i]+fi[i-1];
        S.insert(fi[i]);
        i++;
    }
}

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
    fib();
   // for(int i = 0;i<50;i++){cout<<fi[i]<<endl;}

   /*set<int>::iterator iter = S.begin();
   for(iter;iter!= S.end();iter++){

    cout<<*iter<<endl;
   }*/
    int n,m;
    while(cin>>n>>m){
            memset(jz,0,sizeof(jz));
            init(n-1);
        for(int i = 0;i<n;i++){
            cin>>nlz[i];
        }
         for(int i = 0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--;v--;
            unite(u,v);
        }
        for(int i = 0;i<n;i++){
            //cout<<S.count(nlz[i])<<endl;
            if(S.count(nlz[i])){
                jz[pa[i]]++;
            }
        }
        int ma = 0;
        for(int i = 0;i<n;i++){
            ma = max(ma,jz[pa[i]]);
        }
        /*for(int i=0;i<n;++i)
        {

            for(int j=0;j<n;++j)
            {

                if(i!=j && same(i,j) && flag[i])ans++;
            }
            max
        }*/
        cout<<ma<<endl;
    }
}

