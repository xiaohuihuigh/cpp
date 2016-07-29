//#include<bits/stdc++.h>
//using namespace std;
//using namespace std;
//#define INF 0x3FFFFFFF
//#define PB(X) push_back(X)
//#define MP(X,Y) make_pair(X,Y)
//#define lson l,m,rt<<1
//#define rson m+1,r,tr<<1|1
//typedef pair<int,int>PII;
//typedef vector<PII>VII;
//const int MAXN = 110;
//inline int input() { int x; scanf("%d", &x); return x;}
//inline void print(char s = NULL,int t = 0){printf("%s%d ",s,t);}
//
//double x1[MAXN];
//double yy1[MAXN];
//int main(){
//    ios::sync_with_stdio(false);
//    int n1,n2;
//    cin>>n1;
//    for(int i = 0;i<n1;i++){
//        cin>>x1[i]>>yy1[i];
//    }
//    cin>>n2;
//    double ans = 0;
//    for (int i = 0;i<n2 ;i++ ){
//        double c,d;
//        cin>>c>>d;
//        for (int j = 0;j<n1;j++){
//            double a = x1[j];
//            double b = yy1[j];
//            if (c>a&&d<b){
//            	ans+=d-c;
//            }
//            else if(c<a&&b<d){
//            	ans+=b-a;
//            }
//            else if(c<a&&a<d&&d<b){
//                ans+=d-a;
//            }
//            else if(a<c&&c<b&&b<d){
//            	ans+=b-c;
//            }
//        }
//    }
//    printf("%.3lf\n",ans);
//}
//
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
const int MAXN = 110;
inline int input() { int x; scanf("%d", &x); return x;}
inline void print(char s = NULL,int t = 0){printf("%s%d ",s,t);}

double x1[MAXN];
double x2[MAXN];
double yy1[MAXN];
double y2[MAXN];

int main(){
    ios::sync_with_stdio(false);
    int n1,n2;
    cin>>n1;
    for(int i = 0;i<n1;i++){
        cin>>x1[i]>>yy1[i];
    }
    cin>>n2;
    for (int i = 0;i<n2 ;i++ ){
        cin>>x2[i]>>y2[i];
    }
    int x = 0,y = 0;
    double ans = 0;
    while(1){
        if(x>n1||y>n2)break;
         double a = x1[x],b = yy1[x];
         double c = x2[y],d = y2[y];
         if (a<=c&&c<=d&&d<=b){
            ans += d-c;
            y++;
         }
         else if (a<=c&&c<=b&&b<=d){
            ans += b-c;
            x++;
         }
         else if(a<=b&&b<=c&&c<=d){
            x++;
         }
         else if(c<=a&&a<=b&&b<=d){
            ans+= b-a;
            x++;
         }
         else if(c<=a&&a<=d&&d<=b){
            ans += d-a;
            y++;
         }
         else if(c<=d&&d<=a&&a<=b){
            y++;
         }
    }
    printf("%.3lf\n",ans);
}
