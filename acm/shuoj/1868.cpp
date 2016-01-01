#include<iostream>
#include<string>
#include<cmath>

using namespace std;
int main(){
    string a;
    while(cin>>a){
        long long num = 0;
        int l = a.length();
        int j = 0;
        for(int i = l-1;i>=0;i--){
            if(a[j] == '1')num += pow(2,i);
            if(a[j] == 'u')num -= pow(2,i);
            j++;
        }
        cout<<num<<endl;
    }
}
