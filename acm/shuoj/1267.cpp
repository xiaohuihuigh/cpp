//vijos-p1004
#include <iostream>
using namespace std;

int main()
{
    int T,x,y,z;
    cin>>T;
    while(T--){
        cin>>x>>y>>z;
        if((y==9&&z==30)||(y==11&&z==30))
            cout<<"YES"<<endl;
        else if((y+z)&1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
