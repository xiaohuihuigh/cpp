#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    int T;
    while(cin>>T){
        for(int i = 0;i<T;i++){
            cin>>a[i];
        }
        sort(a,a+T);
        for(int i=  0;i<T;i++){
            if(i != 0)cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
}
