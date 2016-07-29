/*错因：由于左值和右值表示含义发声改变*/
//#include<cstdio>
//#include<algorithm>
//#include<iostream>
//using namespace std;
//#define XINF INT_MAX
//#define INF 0x3FFFFFFF
//#define mp(X,Y) make_pair(X,Y)
//#define pb(X) push_back(X)
//#define rep(X,N) for(int X=0;X<N;X++)
//#define rep1(X,L,R) for(int X=L;X<=R;X++)
//#define dep(X,R,L) for(int X=R;X>=L;X--)
//#define clr(A,X) memset(A,X,sizeof(A))
//#define it iterator
//#define lson l,m,((rt)<<1)
//#define rson m+1,r,((rt)<<1|1)
//#define in(x) scanf("%d",&x)
//#define in2(x,y) scanf("%d%d",&x,&y)
//#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
//#define out1(x)  printf("%d\n",x)
//typedef long long ll;
//const int maxn = 100100;
//int lb(int i){return (-i)&i;}
//template<typename X>
//struct tree_arr{
//    X bits[maxn];
//    int n;
//    void init(int s){n = s;rep1(i,1,s)bits[i] = 0;}
//    void add(int i,X y){while(i<=n){bits[i]+=y;i+=lb(i);}}
//    X query(int i){X s = 0;while(i>0){s+=bits[i];i-=lb(i);}return s;}
//};
//struct node{
//    int l,r,id;
//}p[maxn];
//int cmp(node a,node b){
//    if(a.l == b.l)return a.r<b.r;
//    return a.l<b.l;
//}
//tree_arr<int> tr;
//int ans[maxn];
//int main(){
//    int n;
//    while(in(n)&&n){
//        int ma = 0;
//
//        rep1(i,1,n){
//            in2(p[i].l,p[i].r);
//            p[i].id = i;
//            ma = max(ma,p[i].r);
//        }
//        tr.init(ma+1);
//        sort(p+1,p+n+1,cmp);
//        rep1(i,1,n){
////            cout<<p[i].l<<" "<<p[i].r<<" "<<p[i].id<<endl;
//            int r = ma - p[i].r + 1;
////            cout<<t<<endl;
//            if(p[i].l == p[i-1].l&&p[i].r == p[i-1].r)
//                ans[p[i].id] = ans[p[i-1].id];
//            else ans[p[i].id] = tr.query(r);
//            tr.add(r,1);
//        }printf("%d",ans[1]);
//        rep1(i,2,n){
//            printf(" %d",ans[i]);
//        } printf("\n");
//    }
//    return 0;
//}
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep1(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define it iterator
#define lson l,m,((rt)<<1)
#define rson m+1,r,((rt)<<1|1)
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  printf("%d\n",x)
typedef long long ll;
const int maxn = 100100;
int lb(int i){return (-i)&i;}
template<typename X>
struct tree_arr{
    X bits[maxn];
    int n;
    void init(int s){n = s;rep1(i,1,s)bits[i] = 0;}
    void add(int i,X y){while(i<=n){bits[i]+=y;i+=lb(i);}}
    X query(int i){X s = 0;while(i>0){s+=bits[i];i-=lb(i);}return s;}
};
struct node{
    int l,r,id;
}p[maxn];
int cmp(node a,node b){
    if(a.r == b.r)return a.l<b.l;
    return a.r>b.r;
}
tree_arr<int> tr;
int ans[maxn];
int main(){
    int n;
    while(in(n)&&n){
        int ma = 0;
        rep1(i,1,n){
            in2(p[i].l,p[i].r);
            p[i].id = i;
            ma = max(ma,p[i].l+1);
        }
        tr.init(ma);
        sort(p+1,p+n+1,cmp);
        rep1(i,1,n){
            int l = p[i].l+1;
//            cout<<t<<endl;
            if(p[i].l == p[i-1].l&&p[i].r == p[i-1].r)
                ans[p[i].id] = ans[p[i-1].id];
            else ans[p[i].id] = tr.query(l);
            tr.add(l,1);
//            cout<<p[i].l<<" "<<p[i].r<<" "<<p[i].id<<endl;
        }
        printf("%d",ans[1]);
        rep1(i,2,n){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
