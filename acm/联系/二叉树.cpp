#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string s[10000];
string k[10000];
bool fh(string a){
    if(a =="+"||a == "-"||a == "*"||a == "/"){return 1;}
    else if(a == "&")return 0;
    else return 2;
}
int cr(int i,int root){
    k[root] = s[i];
    if(fh(k[root])==1){
        cr(i++,root*2);
        cr(i++,root*2+1);

    }
}

double sh(int root){
    if(fh(k[root]) == 2)return atof(k[root]);
    if(k[root] == '-')
        return sh(root*2) - sh(root*2+1);
        if(k[root]== '*')
        return sh(root*2) * sh(root*2+1);
        if(k[root]== '+')
        return sh(root*2) + sh(root*2+1);
        if(k[root] == '/')
        return sh(root*2) / sh(root*2+1);
}
int main(){
    for(int i = 0;i<10000;i++)memset(s[i],'&',sizeof(s[i]));
    int i = 0;
    while(getline(cin,s[i++],' ')&&s[i-1]!='\n');
    cr(0,1);
    cout<<sh(1);
}
