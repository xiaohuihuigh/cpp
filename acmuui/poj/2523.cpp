#include<iostream>
using namespace std;
const int maxn = 50005;
int pa[maxn];
int ra[maxn];
void init(int n){
    for(int i = 0;i<=n;i++){
        pa[i] = i;
        ra[i] = 0;
    }
}
int find(int x){
    if(pa[x] != x) pa[x] = find(pa[x]);
    return pa[x];
}
int unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    if(ra[x]>ra[y])
        pa[y] = x;
    else{
        pa[x] = y;
        if(ra[x] == ra[y])
            ra[y]++;
    }
    return 1;
}
bool same(int x,int y){
    return find(x) == find(y);
}

int main(){
    int  n,m;
    int ca = 0;
    while(cin>>n>>m&&!(n==0&&m==0)){
        init(n);
        while(m--){
            int a,b;
            cin>>a>>b;
            unite(a,b);
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(pa[i] == i)ans++;
        }
        cout<<"Case "<<++ca<<": ";
        cout<<ans<<endl;
    }
    return 0;
}

