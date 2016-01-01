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

/***************************
//Floyd
***************************/
#define INF 0x3FFFFFFF
const int MAXN = 310;
int G[MAXN][MAXN];
void init(int n){
    for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
        G[i][j] = INF;
}
void Floyd(int n){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
            }
        }
    }
}
