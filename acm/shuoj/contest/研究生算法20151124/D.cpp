#include<bits/stdc++.h>
using namespace std;
int main(){
   int a[11];
   while(cin>>a[0]){
    for(int i = 1;i<10;i++){

        cin>>a[i];
    }
    int b;
    cin>>b;
    int ans = 0;
    for(int i = 0;i<10;i++){
        if(a[i]-30<=b){
            ans++;
        }


    }
    cout<<ans<<endl;
   }
    return 0;
}
