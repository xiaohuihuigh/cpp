#include<bits/stdc++.h>
using namespace std;
int x[600000];
int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        ios::sync_with_stdio(false);
        for (int i = 0;i<n;i++){
        	cin>>x[i];
        }
        sort(x,x+n);
        int ans = n;
        int pt = n/2;
        for(int i = 0;i<n/2;i++){
            while(1){
                if(x[i]*2<=x[pt]){
                    ans-=1;
                    pt++;
                    break;
                }
                else if(x[i]*2>x[pt]){
                    pt++;
                }
                if(pt == n)break;
            }
            if(pt == n)break;
        }
        cout<<ans<<endl;
    }
}
