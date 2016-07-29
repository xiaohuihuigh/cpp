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

//bool is_su(int a){
//    for(int i = 2;i<=sqrt(a);i++){
//        if(a%i == 0)return false;
//    }
//    return true;
//}
//void su(int a){
//    int day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
////    int day[2] = [0,6];
//    int tw = (a == 1988?1:0);
//    for(int t = 1;t<13;t++){
//        int mad = day[t];
//        if(t == 2)mad+=tw;
//        for(int d = 1;d<=mad;d++){
//            int ma = a*10000+t*100+d;
//            if(is_su(ma))cout<<ma<<endl;
//        }
//    }
//}
char *s = "19880101\n\
19880111\n\
19880117\n\
19880129\n\
19880221\n\
19880317\n\
19880321\n\
19880323\n\
19880417\n\
19880501\n\
19880519\n\
19880521\n\
19880603\n\
19880629\n\
19880711\n\
19880719\n\
19880723\n\
19880807\n\
19880911\n\
19881019\n\
19881101\n\
19881227\n\
19881229\n\
19890103\n\
19890107\n\
19890307\n\
19890413\n\
19890503\n\
19890509\n\
19890517\n\
19890523\n\
19890707\n\
19890713\n\
19890817\n\
19890911\n\
19890919\n\
19891007\n\
19891019\n\
19891031\n\
19891103\n\
19891117\n\
19891127\n\
19891213\n\
19891229\n";
int main(){
    ios::sync_with_stdio(false);
    cout<<s<<endl;
//    int a = 1988;
//    int b = 1989;
//    su(a);su(b);
}


