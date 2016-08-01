#include<bits/stdc++.h>
using namespace std;
#define XINF ll_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define repp(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define fors(i,s) for(auto i = (s).begin();i!=(s).end();i++)
#define all(s) (s).begin(),(s).end()
#define clr(A,X) memset(A,X,sizeof(A))
#define it iterator
#define lson l,m,((rt)<<1)
#define rson m+1,r,((rt)<<1|1)
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  prllf("%lld\n",x)
typedef long long ll;
typedef long long LL;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const int maxn = 1028;

struct IP{
    int id;
    ll num;
    IP(int id,ll num):id(id),num(num){}
};
typedef struct node{
    node *next[2];
    vector<IP> R;
    node(){
        next[0] = next[1] = NULL;
        R.clear();
    }
}node,*Trie;

Trie root = new node();


bool ok[maxn];
int ans[maxn];
int cas;
void creatTire(int mask,ll ip,int id){
    node *p = root;
    rep(i,mask){
        int id = ((ip>>31 - i)&1) == 1?1:0;
        if(p->next[id] == NULL){
            p->next[id] = new node();
        }
        p = p->next[id];
    }
    p->R.pb(IP(id,ip));
    return;
}
ll readIp(){
    int a,b,c,d;
    scanf("%d.%d.%d.%d",&a,&b,&c,&d);
    ll res = 0;
    res |= (ll) a,res<<=8;
    res |= (ll) b,res<<=8;
    res |= (ll) c,res<<=8;
    res |= (ll) d;
    return res;
}


void findS(ll ip){
    Trie p = root;
    rep(i,32){
        int id = ((ip>>(31 - i))&1) == 1?1:0;
        int sz = p->R.size();
        rep(j,sz){
            if (ok[p->R[j].id]&&(ip&(((1ll<<(31-i))-1)))<=p->R[j].num){
            	ans[p->R[j].id] = cas;
            }

        }
        if(p->next[id] == NULL) return ;
            p = p->next[id];
    }
    return;
}


bool findD(ll ip){
    Trie p = root;
    rep(i,32){
        int id = ((ip>>(31 - i))&1) == 1?1:0;
        int sz = p->R.size();
        rep(j,sz){
            if (ok[ p->R[j].id ]&&(ip&( ( (1ll<<(31-i))-1)))<=p->R[j].num){
                if(ans[p->R[j].id] == cas){
                    return true;
            	}
            }
        }
        if(p->next[id] == NULL) return false;
            p = p->next[id];
    }
    return false;
}

int main(){
    char op[4];
    memset(ok,false,sizeof(ok));
    cas = 0;
    while(scanf("%s",op) == 1){
        if(op[0] == 'E'){
            int id;
            in(id);
            ok[id] = true;
            int n;
            in(n);
            rep(i,n){
                int mask;
                ll ip = readIp();
                scanf("/%d",&mask);
                ip+=(1ll<<(32 - mask)) - 1;
                creatTire(mask,ip,id);
            }
        }
        else if(op[0] == 'D'){
            int id;
            in(id);
            ok[id] = false;
        }
        else{
            ++cas;
            ll ips = readIp();
            findS(ips);
            ll ipd = readIp();
            if(findD(ipd))puts("F");
            else puts("D");
        }
    }
    return 0;
}












//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <vector>
//#include <algorithm>
//
//#define LL long long int
//
//using namespace std;
//
//const int MAXN = 1028;
//
//struct IP
//{
//    int id;
//    LL num;
//    IP( int id, LL num ): id(id), num(num) { }
//};
//
//struct node
//{
//    node *next[2];
//    vector<IP> R;
//    node()
//    {
//        next[0] = next[1] = NULL;
//        R.clear();
//    }
//};
//
//node *root;
//bool ok[MAXN];
//int ans[MAXN];
//int cas;
//
//void Insert( int mask, LL ip, int id )
//{
//    node *p = root;
//    for ( int i = 0; i < mask; ++i )
//    {
//        int id = ( ( ip >> (31 - i) ) & 1 ) == 1 ? 1 : 0;
//        if ( p->next[id] == NULL )
//        {
//            p->next[id] = new node;
//        }
//        p = p->next[id];
//    }
//    p->R.push_back( IP( id, ip ) );
//    return;
//}
//
//LL ReadIP()
//{
//    int a, b, c, d;
//    scanf( "%d.%d.%d.%d", &a, &b, &c, &d );
//    LL res = 0;
//    res |= (LL)a, res <<= 8;
//    res |= (LL)b, res <<= 8;
//    res |= (LL)c, res <<= 8;
//    res |= d;
//    return res;
//}
//
//void FindSRC( LL ip )
//{
//    node *p = root;
//    for ( int i = 0; i < 32; ++i )
//    {
//        int id = ( ( ip >> (31 - i) ) & 1 ) == 1 ? 1 : 0;
//        int sz = p->R.size();
//        for ( int j = 0; j < sz; ++j )
//        {
//            if ( ok[ p->R[j].id ] && ( ip&( ( (1LL << (31-i)) - 1 )) ) <= p->R[j].num )
//                ans[ p->R[j].id ] = cas;
//        }
//        if ( p->next[id] == NULL ) return;
//        p = p->next[id];
//    }
//    return;
//}
//
//bool FindDST( LL ip )
//{
//    node *p = root;
//    for ( int i = 0; i < 32; ++i )
//    {
//        int id = ( ( ip >> (31 - i) ) & 1 ) == 1 ? 1 : 0;
//        int sz = p->R.size();
//        for ( int j = 0; j < sz; ++j )
//        {
//            if ( ok[ p->R[j].id ] && (ip&( ( (1LL << (31-i)) - 1 )) ) <= p->R[j].num )
//            {
//                if ( ans[ p->R[j].id ] == cas )
//                    return true;
//            }
//        }
//        if ( p->next[id] == NULL ) return false;
//        p = p->next[id];
//    }
//    return false;
//}
//
//int main()
//{
//    //freopen( "in.txt", "r", stdin );
//    //freopen( "out.txt", "w", stdout );
//    char op[4];
//    root = new node;
//    memset( ok, false, sizeof(ok) );
//    cas = 0;
//    while ( scanf( "%s", op ) == 1 )
//    {
//        if ( op[0] == 'E' )
//        {
//            int id;
//            scanf( "%d", &id );
//            ok[id] = true;
//
//            int n;
//            scanf( "%d", &n );
//            for ( int i = 0; i < n; ++i )
//            {
//                int mask;
//                LL ip = ReadIP();
//                scanf( "/%d", &mask );
//                ip += ( 1LL << (32 - mask) ) - 1;
//                Insert( mask, ip, id );
//            }
//        }
//        else if ( op[0] == 'D' )
//        {
//            int id;
//            scanf( "%d", &id );
//            ok[id] = false;
//        }
//        else
//        {
//            ++cas;
//            LL IPsrc = ReadIP();
//            FindSRC( IPsrc );
//            LL IPdst = ReadIP();
//            if ( FindDST( IPdst ) ) puts("F");
//            else puts("D");
//        }
//    }
//    return 0;
//}
