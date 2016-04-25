
#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n){
        if(n == 1)cout<<1<<endl;
        else if(n == 2)cout<<1<<endl;
        else {
            cout<<(n-1)/2<<endl;
        }
    }


}
