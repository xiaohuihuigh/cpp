
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

const int maxn = 100005;
int pa[maxn];
int ra[maxn];
int un[maxn];
//int d[maxn];
int init(int n){
    for(int i = 1;i<=n;i++){
        pa[i] = i;
        ra[i] = 0;
        un[i] = 0;
        //d[i] = 0;
    }
}
int find(int x){
    if(pa[x]!= x) pa[x] = find(pa[x]);
    return pa[x];
}
int unite(int x,int y){
    x = find(x);
    y  = find(y);
    if(x == y) return 0;
    if(ra[x] < ra[y])pa[x] = y;
    else{
        pa[y] = x;
        if(ra[x] == ra[y]) ra[x]++;
    }
    return 1;
}
int same(int x,int y){
    return find(x) == find(y);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        init(n);
        while(m--){
            char s[3];
            scanf("%s",s);
            if(s[0] == 'A'){
                int a1,a2;
                scanf("%d%d",&a1,&a2);
                //if(d[a1] == 0||d[a2] == 0)
                if(n == 2){
                    printf("In different gangs.\n");
                }
                else{
                    if(un[a1] == 0||un[a2] == 0)
                        printf("Not sure yet.\n");
                    else if(same(a1,a2))printf("In the same gang.\n");
                    else if(same(a1,un[a2])||same(a2,un[a1]))printf("In different gangs.\n");
                    else printf("Not sure yet.\n");
                        /*Âß¼­´íÎó
                    if(un[a1] == 0||un[a2] == 0)
                    printf("Not sure yet.\n");
                else{
                    if(same(a1,a2)) printf("In the same gang.\n");
                    else  printf("In different gangs.\n");
                }*/
                }
            }
            else{
                int a1,a2;
                scanf("%d%d",&a1,&a2);
                if(un[a1] == 0&&un[a2] == 0){
                    un[a1] = a2;
                    un[a2] = a1;
                }
                else if(un[a1] != 0&&un[a2] != 0){
                  //  d[a1] = 1;
                 //   d[a2] = 1;
                    unite(a1,un[a2]);
                    unite(a2,un[a1]);
                }
                else{
                    if(un[a1] != 0){
                        un[a2] = a1;
                        unite(a2,un[a1]);
                    }
                    else{
                        un[a1] = a2;
                        unite(a1,un[a2]);
                    }
                }
            }
        }
    }
}



