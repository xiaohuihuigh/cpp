#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long  long ll;
const int maxn = 100005;
ll ji[maxn];
ll ou[maxn];
ll a[maxn];
int  main(){
    int T;
    //cin>>T;
    scanf("%d",&T);
    while(T--){
        int n,q;
       // cin>>n>>q;
        scanf("%d%d",&n,&q);
        memset(ji,0,sizeof(ji));
        memset(ou,0,sizeof(ou));
        memset(a,0,sizeof(a));
        for(int i = 1;i<=n;i++){
            scanf("%lld",&a[i]);
            //cin>>a[i];
            ji[i]  = ji[i-1];
            ou[i]=  ou[i-1];
            a[i]&1?ji[i]++:ou[i]++;
        }
        for(int i  = 0;i<q;i++){
            int l,r;
            //cin>>l>>r;
            scanf("%d%d",&l,&r);
            int x = ji[r] - ji[l-1];
            int y = ou[r]-ou[l-1];
            printf("%lld\n",x*y);
            //cout<<x*y<<endl;
        }
    }
}
