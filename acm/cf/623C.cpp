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
typedef vector<ll> VI;
typedef vector<VI> VVI;

ll sq(ll a){return a*a;}
struct node{
    ll x,y;
    node(ll a = 0,ll b = 0){x = a;y = b;}
    bool operator<(const node a)const{
        return y<a.y;
    }
};
ll n;
vector<node> pts;
VI exto[2];
VI exfrm[2];
bool isok(ll hgr,ll md,ll i1,ll i2){//hgr 一个y坐标md一个距离i1hgr的i，i2找到的i
    VI ex;
    ex.resize(2);
    ex[0] = 0;
    ex[1] = 0;
//    cout<<hgr<<" "<<md<<" "<<i1<<" "<<i2<<endl;
//    cout<<ex[0]<<" "<<ex[1]<<endl;
    if(i1>0){
        ex[0] = exto[0][i1-1];
        ex[1] = exto[1][i1-1];
    }
    if(i2<n-1){
        ex[0] = min(ex[0],exfrm[0][i2+1]);
        ex[1] = max(ex[1],exfrm[1][i2+1]);
    }

    if(sq(ex[1] - ex[0])>md)return 0;
    if(sq(ex[1])+sq(hgr)>md)return 0;
    if(sq(ex[0])+sq(hgr)>md)return 0;
    return 1;
}
bool ispo(ll md){
    ll hgr;
    ll lwid = 0;
    rep(i,n){
        hgr = pts[i].y;
        if(hgr>0)break;
        while((lwid<n)&&(lwid<=i||(sq(hgr - pts[lwid].y)<=md&&sq(hgr)>=sq(pts[lwid].y))))
        ++lwid;
        --lwid;
        while(lwid>i&&sq(pts[lwid].y)>sq(hgr))
        --lwid;
        ++lwid;

        if(isok(hgr,md,i,lwid-1))return 1;
    }
    lwid = n-1;
    dep(i,n-1,0){
        hgr = pts[i].y;
        if(hgr<0)break;
        while((lwid>=0)&&(lwid==i||(sq(hgr - pts[lwid].y)<=md&&sq(hgr)>=sq(pts[lwid].y))))
        --lwid;
        ++lwid;
        while(lwid<i&&sq(pts[lwid].y)>sq(hgr))
        ++lwid;
        --lwid;
//        cout<<lwid<<endl;
        if(isok(hgr,md,lwid+1,i))return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
    pts.resize(n);
    ll mny = 1e9;
    ll mxy = -mny;
    ll mnx = 1e9;
    ll mxx = -mnx;
    rep(i,n){
        cin>>pts[i].x>>pts[i].y;
        mny = min(mny,pts[i].y);
        mnx = min(mnx,pts[i].x);
        mxy = max(mxy,pts[i].y);
        mxx = max(mxx,pts[i].x);
    }
    sort(all(pts));
    rep(i,2){
    	exto[i].resize(n);
    	exfrm[i].resize(n);
    }
    exto[0][0] = exto[1][0] = pts[0].x;
    exfrm[0][n-1] = exfrm[1][n-1] = pts[n-1].x;
    repp(i,1,n-1){
        exto[0][i] = min(exto[0][i-1],pts[i].x);
        exto[1][i] = max(exto[1][i-1],pts[i].x);
    }
    dep(i,n-2,0){
        exfrm[0][i] = min(exfrm[0][i+1],pts[i].x);
        exfrm[1][i] = max(exfrm[1][i+1],pts[i].x);
    }
    ll l = 0;
    ll r = min(sq(mxy - mny),sq(mxx - mnx));
    ll mid;
    while(l<r){
        ll mid = (l+r)/2;
//        cout<<mid<<" "<<l<<" "<<r<<endl;
        if(ispo(mid)) r = mid;
        else l = mid+1;

    }
    cout<<r<<endl;}
}
