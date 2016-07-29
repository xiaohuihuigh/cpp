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
int ss[4][3] = {1,2,3,4,5,6,7,8,9,-1,0,-1};
int x[100];
int y[100];
int main(){
    ios::sync_with_stdio(false);
    int n;
    string s;
    while(cin>>n){
        cin>>s;
        for(int i = 0;i<n;i++){
            int t = s[i] - '0';
            for(int j = 0;j<4;j++){
                for(int k = 0;k<3;k++){
                    if(t == ss[j][k]){
                        x[i] = j;
                        y[i] = k;
                    }
                }
            }
        }
        int yn = 0;
        int x0,y0;
            x0 = x[0];
            y0 = y[0];
        for(int i = 0;i<n;i++){x[i]-=x0;y[i]-=y0;}
        for(int i = 0;i<4;i++){
            for(int j = 0;j<3;j++){
            if (i == x0&&j == y0)continue;
            for(int j = 0;j<n;j++){
                int t = x[j];
                int tt = y[j];
                t+=i;
                tt+=j;
                if((t>=0&&t<3&&tt>=0&&tt<3)||(t == 3&&tt == 1)){
                    yn = 0;
                    //cout<<t<<" "<<y[j]<<endl;
                }
                else {yn = 1;/*cout<<"brea"<<endl;*/break;}
            }
            if(yn == 0)break;
            }
            if(yn == 0)break;
            }

        if(yn == 0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}



