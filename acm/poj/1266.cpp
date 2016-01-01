//#include<bits\stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 105;
int next[maxn];
int ans[maxn];
string s[maxn];
void getnext(string a)
{
    int i = 0;int j = -1;
    next[0] = -1;
    while(i<a.length()){
        if(j == -1||a[i] == a[j])
        {
            i++;j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int kmp(string a,string b){
    getnext(a);
    int ans = 0;
    int al = a.size();
    int bl = b.size();
    //cout<<b<<endl;
    int i = 0;int j = 0;
    while(i<bl){
        if(j == -1||a[j] == b[i]){
            //cout<<i<<" "<<j<<a[j]<<b[i]<<endl;
            i++;j++;

        }
        else{
            j = next[j];
        }
         ans = max(ans,j);
        if(j == al)
            j = next[j];
    }
    return ans;
}
string jianyi(string a){
    string b = a;
    reverse(b.begin(),b.end());
    b = b.substr(0,b.size()-1);
    reverse(b.begin(),b.end());
    return b;
}
int main() {
    int T;
    cin>>T;
    while(T--){
            memset(ans,0x3f,sizeof(ans));
        int n;
        cin>>n;
        if(n == 0) {cout<<"0"<<endl;continue;}
        if(n == 1){
            cin>>s[0];
            cout<<s[0].size()<<endl;
            continue;
        }
        int mini = 0;
        int minsize = 0x3f3f3f;
        for(int i = 0;i<n;i++){
            cin>>s[i];
            if(s[i].size()<minsize)
            {
                minsize = s[i].size();
                mini = i;
            }
            }
             string a = s[mini];
        for(int i = 0;i<s[mini].length();i++){
            for(int j = 0;j<n;j++){
                    if(j == mini)continue;
                    string b = s[j];
                    string cc = s[j];
                    reverse(cc.begin(),cc.end());
                    b = b+"@"+cc;
                ans[i] = min(ans[i],kmp(a,b));
            }
           // cout<<ans[i]<<endl;
           a = jianyi(a);
        }
        int ant = 0;
        for(int i = 0;i<s[mini].length();i++){
                //cout<<ans[i];
            ant = max(ant,ans[i]);
        }
        cout<<ant<<endl;
        }



    return 0;
}
