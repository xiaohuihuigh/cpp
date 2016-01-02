#include<iostream>
using namespace std;
int a[7];
int main(){
int ma = 0;int t = 0;
    for(int i = 0;i<7;i++){
        int c,b;
        cin>>c>>b;
        a[i] = c+b;
        if(a[i]>ma){
        ma = a[i];
        t = i;
        }
    }
    if(a[t]>8)
    cout<<t+1<<endl;
    else cout<<0<<endl;
}
