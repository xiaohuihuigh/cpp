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
/*************************
//Bellman-FordËã·¨
**************************/
#define INF 0x3FFFFFFF
const int MAXN_EDGE = 10010;
const int MAXN_NODE = 1010;
int dis[MAXN_NODE];
int From[MAXN_EDGE];
int To[MAXN_EDGE];
int w[MAXN_EDGE];
int tot;
void init(int n){
    tot = 0;
}
void add_edge(int u,int v,int d){
    From[tot] = u;
    To[tot] = v;
    w[tot++] = d;
}
bool Bellman_Ford(int s,int n){
    for(int i=0;i<n;i++)dis[i] = (i == s ? 0 :INF);//初始化
    for(int k=0;k<n-1;k++){//松弛
        for(int i=0;i<tot;i++){
            int x = From[i];
            int y = To[i];
            dis[y] = min(dis[y], dis[x] + w[i]);
        }
    }
    for(int i=0;i<tot;i++){//判断负环
            int x = From[i];
            int y = To[i];
           if( w[i]+dis[x]<dis[y])
            return false;
           else return true;
        }
}
