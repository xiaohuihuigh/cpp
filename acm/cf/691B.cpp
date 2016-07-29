
#include<bits/stdc++.h>
using namespace std;
using namespace std;
#define INF 0x3FFFFFFF
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define lson l,m,rt<<1
#define rson m+1,r,tr<<1|1
typedef pair<int,int>PII;
typedef vector<PII>VII;
const int MAXN = 100010;
inline int input() { int x; scanf("%d", &x); return x;}
inline void print(char s = NULL,int t = 0){printf("%s%d ",s,t);}
string sd = "A@@@@@@HI@@@M@O@@@@TUVWXY@";
string sx = "@d@b@@@@i@@@@@oqp@@@@vwx@@";
int main(){
    ios::sync_with_stdio(false);
    string s;
    while(cin>>s){
        int len = s.length();
        int yn = 1;
        for(int i = 0;i<len/2+1;i++){
//            cout<<s[i]<<endl;
            if(s[i]>='A'&&s[i]<='Z'){
                if(s[i] != sd[s[len-1-i] - 'A']){
                    yn = 0;
                    break;
                }
            }
            else{
                if(s[i] != sx[s[len-1-i] - 'a']){
                    yn = 0;
                    break;
                }
            }
        }
        if(yn == 0)cout<<"NIE"<<endl;
        else cout<<"TAK"<<endl;
    }
}


