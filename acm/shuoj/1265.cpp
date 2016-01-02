#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[10100];
int f[10100];
int main(){
    int L;
    while(cin>>L){
        int s,n,m;
        cin>>s>>n>>m;
        for(int i = 1;i<=m;i++)
            cin>>a[i];
            a[0] = 0;
        sort(a,a+m+1);
        if(s == n){
        int ans = 0;
            for(int i= 1;i<=m;i++){
                if(a[i]%s == 0)ans ++;
            }
            cout<<ans<<endl;continue;
        }
        int t  = 0;
        a[0]= 0;
        memset(b,0,sizeof(0));
        memset(f,0x3f,sizeof(f));
        for(int i = 1;i<=m;i++){
            if(a[i]-a[i-1] >100)t+=100;
            else t+=a[i] - a[i-1];
            b[t] = 1;
       }
       f[0] = 0;
        for(int i =1;i<=t+100;i++){
            for(int j = s;j<=n;j++){
                if(i>=j)f[i] = min(f[i],f[i-j]+b[i]);
            }
           // cout<<"i"<<i<<" "<<f[i]<<endl;
        }
        cout<<f[t+100]<<endl;
    }
}
