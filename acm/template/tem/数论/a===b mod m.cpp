//ax === b mod m.cpp
/*
ax === b(mod m)相当于ax +my = b
根据前面求  ax+my = b的步骤：
（1）求x,y,t = gcd(a,m)
（2）如果b%d!=0无解
（3） 由ax+my = t,得a(x*b/t)+m(y*b/t) = b
    于是ax===b(mod m)的一个解为x = x*b/t
 （4）ax === b(mod m)的所有解为：
        x = (x*b/t+ i*m/t)mod m,i = 0,1,2,...d-1
*/
#include<iostream>
using namespace std;
int main(){
    long long  a,b,x,m,y;
    while(cin>>a>>b>>m){
        long long t = extend_gcd(a,m,x,y);//拓展欧几里得
        if(b%t == 0){
            x =(x*b/t)%m;
        while(x<0)x = (x+m)%m;
            for(int i = 0;i<t;i++){
                cout<<(x+i*(m/t))%m<<endl;
                }
        }
        else cout<<"no solutions"<<endl;

    }
}
