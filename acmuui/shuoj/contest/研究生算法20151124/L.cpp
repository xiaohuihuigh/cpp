
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
    int n;
    while(cin>>n){
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i = 0;i<n;i++){
                if(i != 0)cout<<" ";
                cout<<a[i];
        }
        cout<<endl;
    }
}
