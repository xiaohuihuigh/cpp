
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
int main(){
    ios::sync_with_stdio(false);
    string s;
    while(cin>>s){
        int len = s.length();
        int has_p = -1;
        int start = -1,end = -1;
        int cnt = -1;
        for(int i = 0;i<len;i++){
            if(s[i] == '.'){
                has_p = i;break;
            }
        }
        for(int i = 0;i<len;i++){
            if(s[i] == '.');
            else if(s[i] == '0');
            else{
                start = i;break;
            }
        }
        for(int i = len-1;i>=0;i--){
            if(s[i] == '.');
            else if(s[i] == '0');
            else{
                end = i;break;
            }
        }
//        for(int i = start;i<=end;i++){
//            cout<<s[i];
//        }
        if(start == -1){cout<<"0"<<endl;continue;}
        if(has_p == -1)has_p = len;
        cnt = has_p - start;
        if(cnt>0)cnt-=1;
        if(cnt == 0){
            if(end>start)
            for(int i = start;i<=end;i++){
                if(i == start){cout<<s[i]<<".";}
                else if(s[i] == '.');
                else cout<<s[i];
            }
            else{
                cout<<s[start];
            }
        }

        else{
            if(end>start)
            for(int i = start;i<=end;i++){
                if(i == start){cout<<s[i]<<".";}
                else if(s[i] == '.');
                else cout<<s[i];
            }else{
                cout<<s[start];
            }
            cout<<"E"<<cnt;
        }
        cout<<endl;




















//        int znum = 0;
//        int zs = 0;
//        int pnum = 0;
//        int zp = 0;
//        int ps = 0;
//        int pe = 0;
//        for(int i = 0;i<len;i++){
//            if(s[i] == 0&&zs == 0){;
//            }
//            else{
//                zs = 1;
//                if(s[i]!= '.'&&zp == 0){
//                    ps = i;
//                    zp = 1;
//                }
//                if(s[i] == '.'){
//                    zp = i - ps;
//            }
//            }
//
//        }
//        for(int i = len-1;i>0;i--){
//            if(s[i] == 0&&pe == 0){;
//            }
//            else{
//                pe = i;
//                break;
//            }
//
//        }
//        if(zp == 1){
//            for(int i = ps;i<=pe;i++){
//                if(i == ps){cout<<s[i]<<".";}
//                if(s[i] == '.');
//                else cout<<s[i];
//            }
//        }
//        else{
//            for(int i = ps;i<=pe;i++){
//                if(i == ps){cout<<s[i]<<".";}
//                if(s[i] == '.');
//                else cout<<s[i];
//            }
//            cout<<"E"<<zp<<endl;
//        }
//    }
    }
}


