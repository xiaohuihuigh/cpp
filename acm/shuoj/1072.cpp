#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n){
            int ans  =0;
            int y = 0;
        while(n>=3){
            ans+=n/3;
            y = n%3;
            n/=3;
            n +=y;

        }
        if(n == 2) ans ++;
        cout<<ans<<endl;
    }
}
