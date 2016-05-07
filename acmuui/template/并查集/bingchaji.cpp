
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
const int MAXN = 1000;
int pa[MAXN];
int ra[MAXN];
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

const int maxn = 1000;

int pa[maxn];
int ra[maxn];
void init(int n){
    for(int i = 0;i<=n;i++){
        pa[i] = i;
        ra[i] = 0;
    }
}
int find(int x){
    if(pa[x]!= x)pa[x] = find(pa[x]);
    return pa[x];
}
int unint(int x,int y){
    x = find[x];
    y = find[y];
    if(x == y) return 0;
    if(ra[x]>ra[y]){
        pa[y] = x;
    }
    else {
        pa[x] = y;
        if(ra[x] == ra[y])ra[y]++;
    }
    return 1;
}

void same(int x,int y){
    return find(x) == find(y);
}







