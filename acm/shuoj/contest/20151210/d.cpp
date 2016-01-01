
#include<iostream>
using namespace std;
const double pi = 3.1415926;
int main(){
    double r,v1,v2;
    while(cin>>r>>v1>>v2){
        double t1,t2;
        t1 = r/v1;
        t2 = r*pi/v2;
        if(t1>t2)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
