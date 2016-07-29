#include<bits/stdc++.h>
using namespace std;
int f[1005];
string s;
bool palin(int x,int y){
    while(x<y){
        if(s[x] != s[y])return false;
        x++,y--;
    }
    return true;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>s;
        int n = s.length();
        for(int i = 0;i<n;i++){
            f[i] = i+1;
            for(int j = 0;j<=i;j++){
                if(palin(j,i)){
                    if(j == 0)f[i] = min(f[i],1);
                    f[i] = min(f[i],f[j-1]+1);
                }
            }
        }
        cout<<f[n-1]<<endl;
    }
    return 0;
}
