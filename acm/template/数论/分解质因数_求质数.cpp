#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1200021;
int cntP[N],isP[N];
int main(){
    ios::sync_with_stdio(false);
    memset(isP,0,sizeof(isP));
    //求质数（if isP[i] = i）
    for(int i = 2;i<N;i++)
        if(!isP[i])
            for(int j = i;j<N;j+=i)
                isP[j] = i;

    //分解质因数，
    int x,xx;cin>>x;xx = x;
    while(x>1){
        cntP[isP[x]]++;
        x/=isP[x];
    }

    //求n个数lcm的因式分解
    int n;cin>>n;
    for(int i = 0;i<n;i++){
        int x;cin>>x;
        while(x>1){//分解质因数，搞成模板才好
            int p = isP[x];
            int cnt = 0;
            while(!(x%p)){
                cnt++;
                x /= p;
            }
            cntP[p] = max(cntP[p],cnt);
        }
    }
    //求n个数的lcm是否整除k
    int k;cin>>k;
    bool ok = 1;
    while(k>1){
        ok &= (cntP[isP[k]]>0);
        cntP[isP[k]]--;
        k/=isP[k];
        if(!ok)break;
    }
    cout<<(ok?"Yes\n":"No\n");

}




