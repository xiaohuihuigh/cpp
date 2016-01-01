#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        long long x,y;
        cin>>x>>y;
       unsigned long long  num;
       if(x>y)num = x-y;
       else num = y-x;
       // if(num>0)
            cout<<num<<endl;
       // else cout<<-num<<endl;

    }
    return 0;
}
