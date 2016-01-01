#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int x,n;
        cin>>x>>n;
        if(n == 0)cout<<x<<endl;
        else {
            if(x == 1||x== 3){
                if(n%2 == 0)
                    cout<<"1"<<endl;
                else cout<<"2"<<endl;
            }
            else {
                if(n%2 == 0)
                    cout<<"2"<<endl;
                else cout<<"1"<<endl;
            }
        }

    }
    return 0;
}
