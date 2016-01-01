#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    int t = 1;int yn = 0;
    getchar();
    while(yn == 0){

        if(t>n){
            yn = 1;
           while(cin>>s){
            cout<<s<<endl<<endl;
           }
           goto END;
        }
        getline(cin,s);
        cout<<s<<endl<<endl;
        t++;
    }END:
    return 0;
}
