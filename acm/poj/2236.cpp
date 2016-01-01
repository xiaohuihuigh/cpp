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

const int maxn = 1005;
int pa[maxn];
int ra[maxn];
int repair[maxn];

    int x[maxn],y[maxn];
    int n,d;
int init(int n){
    for(int i  = 1;i<=n;i++){
        pa[i]  =i;
        ra[i] = 0;
    }
}
int find(int x){
    if(pa[x] != x) pa[x] = find(pa[x]);
    return pa[x];
}
int unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    if(ra[x]>ra[y]) pa[y] = x;
    else{
        pa[x] = y;
        if(ra[x] == ra[y]) ra[y]++;
    }
}
int same(int x,int y){
    return find(x)==find(y);
}
bool xiaod(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=d*d;
    return 0;

}
void jisuan(int t){
    for(int i = 1;i<=n;i++){
        if(xiaod(x[i],y[i],x[t],y[t])&&repair[i])unite(i,t);
    }
}

int main(){
    scanf("%d%d",&n,&d);
    init(n);
    for(int i = 1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    memset(repair , 0 , sizeof(repair));
    char s[10];
    while(scanf("%s",s)!=EOF){
        if(s[0] == 'O'){
            int t;
            scanf("%d",&t);
            jisuan(t);
            repair[t] = 1;
        }
        else{
                int a1,a2;
            scanf("%d%d",&a1,&a2);
            if(same(a1,a2))printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
}

