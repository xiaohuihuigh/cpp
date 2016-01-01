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
#define INF 0x3FFFFFFF
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
typedef pair<int,int>PII;
typedef vector<PII>VII;

int main(){
    int T;int ca = 0;
    cin>>T;
    getchar();
    while(T--){
        char a[100000] = {0};
        //char b[100000]={0};
        gets(a);
        int l,i;
        int ans = 0;
    l = strlen(a);
    if(a[0] != ' ' && a[0]!=0)ans ++;
    for( i = 0;i<l-1;i++)
    {
        if(a[i] == ' '&&(a[i+1] != ' '&&a[i] != 0)){
            ans ++;
        }
    }
    cout<<"Case "<<++ca<<": "<<ans<<endl;
   // puts(a);
    }
    return 0;
}
