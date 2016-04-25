#include<bits/stdc++.h>
using namespace std;
int d[205];
int main(){
    int a,b,c;
    while(cin>>a>>b>>c){
        for(int i = 0;i<a+b;i++){
            cin>>d[i];
        }
        sort(d,d+a+b);
        cout<<d[c-1]<<endl;
    }
}
