#include<string>
#include<iostream>
using namespace std;
int main(){
    int n;string a,b;
    while(cin>>n>>a>>b){
        if(b[0] == 'w'){
            if(n ==5||n==6)cout<<"53"<<endl;
            else cout<<"52"<<endl;
        }
        if(b[0] == 'm')
            if(n == 31)cout<<"7"<<endl;
            else if(n == 30)cout<<"11"<<endl;
            else cout<<"12"<<endl;
    }
}
