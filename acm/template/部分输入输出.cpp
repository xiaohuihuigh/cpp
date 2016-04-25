#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    string str;
    int x,sum,n,k = 0;
    while(getline(cin,str)){
        istringstream istr(str);
        for(sum = n = 0;istr >> x;n++){
            sum+= x;

        }
        cout<<"sum"<<sum<<"n"<<n<<endl;
    }
}
