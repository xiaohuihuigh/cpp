#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n == 1){cout<<"2"<<endl;continue;}
        int num = sqrt(n*2-1);
        //cout<<num;
        if(n == num*(num+1)/2+1)cout<<"2"<<endl;
        else cout<<"3"<<endl;
    }
}
