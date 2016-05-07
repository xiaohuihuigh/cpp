#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    getline(cin,a);
        int len = a.length();
        for(int i = len-1;i>=0;i--){
            cout<<a[i];
        }
        cout<<endl;
    return 0;
}
