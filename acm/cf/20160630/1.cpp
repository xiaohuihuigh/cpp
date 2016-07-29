#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    while(cin>>n>>d){
        int ans = 0;
        int maxx  = 0;
        string a;
        for(int i = 0;i<d;i++){
            cin>>a;

        int yn = 1;
        for(int i = 0;i<n;i++){
            if (a[i] == '0'){
                yn = 0;
                break;
            }
        }
        if(yn == 0)ans++;
        else ans  = 0;
        maxx = max(maxx,ans);
        }
        cout<<maxx<<endl;
    }

}

