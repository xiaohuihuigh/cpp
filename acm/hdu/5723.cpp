//#include<bits/stdc++.h>
//using namespace std;
//#define N 1000005
//#define ll long long
//vector<pair<int ,int > >V[N];
//struct node{
//    int x,y,w;
//}p[N];
//int n,m,fa[N];
//double ans;
//bool cmp(node a,node b){
//    return a.w<b.w;
//}
//int Find(int x){
//    return x != fa[x]?fa[x] = Find(fa[x]):x;
//}
//bool Union(int x,int y){
//    x = Find(x);
//    y = Find(y);
//    if(x != y){
//        fa[x] = y;
//        return 1;
//    }
//    return 0;
//}
//int dfs(int now,int pre){
//    int tm = 0;
//    for(int i = 0;i<V[now].size();i++){
//        if(V[now][i].first == pre)continue;
//        int cm = dfs(V[now][i].first,now);
//        tm+=cm;
//        ans += 1.0*cm*(n - cm)*V[now][i].second;
//    }
//    return tm+1;
//}
//
//int main(){
//    int t;
//    ll s = 0;
//    scanf("%d",&t);
//    while(t--){
//        s = ans = 0;
//        scanf("%d%d",&n,&m);
//        for(int i = 0;i<=n;i++){
//            fa[i] = i;
//            V[i].clear();
//        }
//        for(int i = 0;i<m;i++){
//            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].w);
//        }
//        sort(p,p+m,cmp);
//        for(int i = 0;i<m;i++){
//            if(Union(p[i].x,p[i].y) == 1){
//                s+=p[i].w;
//                V[p[i].x].push_back(make_pair(p[i].y,p[i].w));
//                V[p[i].y].push_back(make_pair(p[i].x,p[i].w));
//            }
//        }
//        dfs(1,0);
//        ans = ans*2.0/(n)/(n-1);
//        printf("%lld %.2lf\n",s,ans);
//    }
//}
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

typedef long long ll;
const int maxn = 100005;
double ans;
int n,m;
int pa[maxn];
int ra[maxn];
vector<pair<int ,int > >V[maxn];
void init(int n){
    for(int i = 0;i<=n;i++){
        pa[i] = i;
        ra[i] = 0;
        V[i].clear();
    }
}
int find(int x){
    if(pa[x]!=x)pa[x] = find(pa[x]);
    return pa[x];
}
int unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return 0;
    if(ra[x] < ra[y]){
        pa[x] = y;
    }else{
        pa[y] = x;
        if(ra[x] == ra[y])ra[x]++;
    }
    return 1;
}
typedef pair<int,int> PII;
vector<pair<int,PII> > G;

void init_G(){
    G.clear();
}
void add_edge(int u,int v,int d){
    G.push_back(make_pair(d,make_pair(u,v)));
}
ll Kruskal(int n){
    init(n);
    sort(G.begin(),G.end());
    int m = G.size();
    int num = 0;
    ll ret = 0;
    for(int i=0;i<m;i++){
        pair<int,PII> p = G[i];
        int x = p.second.first;
        int y = p.second.second;
        int d = p.first;
        if(unite(x,y)){
//            cout<<x<<"x"<<y<<endl;
//            cout<<ret+d<<endl;
            num++;
            ret =ret + d;
            V[x].pb(mp(y,d));
            V[y].pb(mp(x,d));
        }
        if(num == n-1)break;
    }
    return ret;
}
int dfs(int now,int pre){
    int d = 0;
    for(int i = 0;i<V[now].size();i++){
        if(V[now][i].first == pre)continue;
        int cm = dfs(V[now][i].first,now);
        d+=cm;
        ans += 1.0*cm*(n - cm)*V[now][i].second;
    }
    return d+1;
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        ans = 0;
        cin>>n>>m;
        init_G();
        for (int i = 0;i<m;i++){
        	int x,y,w;
        	cin>>x>>y>>w;
        	G.pb(mp(w,mp(y,x)));
        	G.pb(mp(w,mp(x,y)));
        }
        ll s = Kruskal(n);
        dfs(1,0);
//        cout<<ans<<endl;
        ans = ans*2.0/(n)/(n-1);
//cout<<ans<<endl;
        printf("%lld %.2lf\n",s,ans);
    }
}
