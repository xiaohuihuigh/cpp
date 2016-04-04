
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
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define M_PI 3.14159265358979323846
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define MAX_V 10101
//#define maxn 10
#define lowbit(X) (X & (-X))
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;

/************************************************
********************头文件**********************
************************************************/

const int maxn = 200;
struct bign
{
    int len, s[maxn];
bign()
{
    memset(s, 0, sizeof(s));
    len = 1;
}
bign(int num) {
    *this = num;
}
bign(const char* num) {
    *this = num;
}
bign operator = (int num) {
    char s[maxn];
    sprintf(s, "%d", num);
    *this = s;
    return *this;
}
bign operator = (const char* num) {
    len = strlen(num);
    for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
    return *this;
}
string str() const {
    string res = "";
    for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
    if(res == "") res = "0";
    return res;
}
bign operator + (const bign& b) const{
    bign c;
    c.len = 0;
    for(int i = 0, g = 0; g || i < max(len, b.len); i++) {
      int x = g;
      if(i < len) x += s[i];
      if(i < b.len) x += b.s[i];
      c.s[c.len++] = x % 10;
      g = x / 10;
    }
    return c;
}
void clean() {
    while(len > 1 && !s[len-1]) len--;
}
bign operator * (const bign& b) {
    bign c; c.len = len + b.len;
    for(int i = 0; i < len; i++)
      for(int j = 0; j < b.len; j++)
        c.s[i+j] += s[i] * b.s[j];
    for(int i = 0; i < c.len-1; i++){
      c.s[i+1] += c.s[i] / 10;
      c.s[i] %= 10;
    }
    c.clean();
    return c;
}
bign operator - (const bign& b) {
    bign c; c.len = 0;
    for(int i = 0, g = 0; i < len; i++) {
      int x = s[i] - g;
      if(i < b.len) x -= b.s[i];
      if(x >= 0) g = 0;
      else {
        g = 1;
        x += 10;
      }
      c.s[c.len++] = x;
    }
    c.clean();
    return c;
}
bool operator < (const bign& b) const{
    if(len != b.len) return len < b.len;
    for(int i = len-1; i >= 0; i--)
      if(s[i] != b.s[i]) return s[i] < b.s[i];
    return false;
}
bool operator > (const bign& b) const{
    return b < *this;
}
bool operator <= (const bign& b) {
    return !(b > *this);
}
bool operator == (const bign& b) {
    return !(b < *this) && !(*this < b);
}
bign operator += (const bign& b) {
    *this = *this + b;
    return *this;
}
};
istream& operator >> (istream &in, bign& x) {
string s;
in >> s;
x = s.c_str();
return in;
}
ostream& operator << (ostream &out, const bign& x) {
out << x.str();
return out;
}















string n;
bign num;
int k;
int maps[10][10];
bign cat[10];
int main()
{
    while(cin>>n>>k)
    {

        int x,y;
        memset(cat,0,sizeof(cat));
        memset(maps,0,sizeof(maps));
        REP(i,10) maps[i][i] = 1;
        num = 1;
        REP(i,k)
        {
            cin>>x>>y;
            maps[x][y] = 1;
        }
        REP(k,10)
        REP(i,10)
        REP(j,10)
        {
            maps[i][j] = (maps[i][j]||(maps[i][k]&&maps[k][j]));
        }
        REP(i,10)
        REP(j,10)
        {
            //cout<<i<<" "<<j<<" "<<maps[i][j]<<endl;
            if(maps[i][j])cat[i]= cat[i]+1;
        }
        REP(i,n.length())
        {
            int t = n[i] - '0';
            num = num * cat[t];
        }
        cout<<num<<endl;
    }
    return 0;
}
