
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    while(cin>>a>>b>>c){
        int d[4];
        d[0] = (a+b)*2;
        d[1] = (a+b+c);
        d[2] = (b+c)*2;
        d[3] = (a+c)*2;
        sort(d,d+4);
        cout<<d[0]<<endl;
    }
    return 0;
}
