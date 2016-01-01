#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int a[27];
int main(){
    int T;
    cin>>T;int ca = 0;
    while(T--){
            vector<int> V[27];
        string s;int i = 0;
        cin>>s;
        int mi = INF;
        memset(a,0,sizeof(a));
        for(int i = 0;i<s.length();i++){
              //  cout<<s[i] - 'a';
            V[s[i] - 'a'].push_back(i);
            a[s[i]-'a'] ++;
        }

        for(int j = 0;j<=26;j++){
               // cout<<"V[j].size"<<V[j].size()<<endl;
            for(int k = 1;k<V[j].size();k++){

                mi = min(mi,V[j][k] - V[j][k-1]);
            }
        }
        cout<<"Case #"<<++ca<<": ";
        if(mi == INF)cout<<"-1"<<endl;
        else cout<<mi<<endl;
    }
}
