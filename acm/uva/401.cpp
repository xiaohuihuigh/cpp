#include<string>
#include<iostream>
using namespace std;
char str[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
bool ip(string s){
    int yn = 0;
    int len = s.length();
    for(int i = 0;i<len;i++){
        if(s[i] != s[len-i-1]){yn = 1;break;}
    }
    if(yn)return 0;
    return 1;
}
bool imp(string s){
    int len = s.length();int yn = 0;
    for(int i= 0;i<len;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            if(s[i] != str[s[i]-'A']){yn = 1;break;}
        }
        if(s[i]>='1'&&s[i]<='9'){
            if(s[i] != str[s[i]-'1'+26]){yn = 1;break;}
        }
    }
    if(yn) return 0;
    else return 1;
}
bool ims(string s){
     int len = s.length();int yn = 0;
    for(int i= 0;i<len;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            if(s[len-i-1] != str[s[i]-'A']){yn = 1;break;}
        }
        if(s[i]>='1'&&s[i]<='9'){
            if(s[len-1-i] != str[s[i]-'1'+26]){yn = 1;break;}
        }
    }
    if(yn) return 0;
    else return 1;
}
int main(){
    string s;
    while(cin>>s){
        if(ip(s)){
            if(imp(s)){
                cout<<s<<" -- is a mirrored palindrome."<<endl;
            }
            else{
                cout<<s<<" -- is a regular palindrome."<<endl;
            }
        }
        else if(ims(s)){
            cout<<s<<" -- is a mirrored string."<<endl;
        }
        else cout<<s<<" -- is not a palindrome."<<endl;


        cout<<endl;
    }
}
