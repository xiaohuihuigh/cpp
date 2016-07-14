#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
int a[maxn];
int b[maxn];
int c[maxn];
int sum[maxn*maxn];

int main(){
    int l,m,n;
    int ca = 0;
    while(cin>>l>>m>>n){
        ca++;
        cout<<"Case "<<ca<<":\n";
        for(int i = 0;i<l;i++){
            cin>>a[i];
        }
        for(int i = 0;i<m;i++){
            cin>>b[i];
        }
        for(int i = 0;i<n;i++){
            cin>>c[i];
        }
        for(int i = 0;i<l;i++){
            for(int j = 0;j<m;j++){
                sum[i*m+j] = a[i]+b[j];
            }
        }
        int len = l*m;
        sort(sum+0,sum+len);
        int k;
        cin>>k;
        for(int i = 1;i<=k;i++){
            int s;
            cin>>s;
            int yn = 0;
            for(int j = 0;j<n;j++){
                int l = 0,r = len-1;
                while(l<r){
                    int mid = (l+r-1)/2+1;
                    if(sum[mid]+c[j]<=s) l = mid;
                    else r = mid-1;
                }
                if(sum[l]+c[j]==s){
                    yn = 1;break;
                }
            }
            if(yn)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
