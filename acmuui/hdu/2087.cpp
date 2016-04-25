//#include<bits\stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int Next[1005];
int ans[1005];
string s[1005];
void getNext(string a)
{
    int i = 0;int j = -1;
    Next[0] = -1;
    while(i<a.length()){
        if(j == -1||a[i] == a[j])
        {
            i++;j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}/*
int kmp(string a,string b){
    getNext(a);
    int ans = 0;
    int al = a.size();
    int bl = b.size();
    int i = 0;int j = 0;
    while(i<bl){
        if(j == -1||a[j] == b[i]){
            i++;j++;

        }
        else{
            j = Next[j];
        }
        if(j == al){
			j = Next[j];
			ans++;
		}
    }
    return ans;
}*/
int kmp(string T,string S)
{
    int ans = 0;
    int i, j = 0;
    int slen = S.size();
    int tlen = T.size();
    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    getNext(T);
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = 0;
        }
    }
    return ans;
}

int main() {
    string a;

    while(cin>>a&&!(a[0] == '#'&&a[1] == 0)){
        string b;
        cin>>b;
		cout<<kmp(b,a)<<endl;
        }
    return 0;
}
