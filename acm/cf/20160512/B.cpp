
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int a[maxn];
//int main(){
//    int T;
//    cin>>T;
//    while(T--){
//        int n;
//        cin>>n;
//        for(int i = 0;i<n;i++){
//            cin>>a[i];
//        }
//    }
//}
int main(){
    int n;
    string s;
    int a[55];
    while(cin>>n){
        cin>>s;
        if(n>26){
            cout<<"-1"<<endl;
        }
        else{
            int cnt = 0;
            memset(a,0,sizeof(a));
            for(int i = 0;i<n;i++){
                if(a[s[i] - 'a'] == 0){
                    a[s[i] - 'a'] = 1;
                    cnt++;
                }
            }
            cout<<n - cnt<<endl;
        }
    }
}
//int main(){
//    string s;
//    for(int i = 10;i<99;i++){
//
//    }
//}2
//3
//4
//5
//6
//7
//8
//9
//10
//11
//12
//13
//14
//15
//16
//
//#include <iostream>
//#include <string>
//using namespace std;

