#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],id[105],dp[105];
bool cmp(int x,int y){
    if(a[x]<a[y]){
        return 1;
    }
    else if(a[x] == a[y]&&b[x]<b[y])return 1;
    return 0;
}
int main(){
    int n;
    while(cin>>n&&n!= 0){
        for(int i = 0;i<n;i++){
            cin>>a[i]>>b[i];
            id[i] = i;
        }
        sort(id,id+n,cmp);

    int k = 0;dp[0] = b[id[0]];
    for(int i = 1;i<n;i++){
            if(a[id[i]]>dp[k]){
            dp[++k] = b[id[i]];
          //  cout<<dp[k]<<endl;
            continue;}
            if(b[id[i]]<dp[k]){
                dp[k] = b[id[i]];
               // cout<<dp[k]<<endl;
            }
           // else break;

    }
    cout<<k+1<<endl;
    }
    return 0;

}
