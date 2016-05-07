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
//并查集终极版本
//带两种优化
****************************/
const int MAXN = 2020;
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
int s[MAXN];
int main(){
	int T,ca = 1;
	cin>>T;
	while(T--){
		int n,m;
        scanf("%d%d",&n,&m);
		init(n);
		int yn = 0;
		memset(s,0,sizeof(s));
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			if(same(x,y)){yn = 1;}
			if(s[x] == 0&&s[y] == 0){
				s[x] = y;
				s[y] = x;
			}
			else if(s[x] != 0&&s[y] != 0){
                unite(s[x],y);
                unite(s[y],x);
			}
			else{
				if(s[x] != 0){
					unite(s[x],y);
					s[y] = x;
				}
				if(s[y] != 0){
					unite(s[y],x);
					s[x] = y;
				}

			}

		}
            if(ca != 1)cout<<endl;
            printf("Scenario #%d:\n",ca++);
			if(yn)
				cout<<"Suspicious bugs found!"<<endl;
			else cout<<"No suspicious bugs found!"<<endl;

	}
}
