#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    getchar();
    while(T--){
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        int l1,l2;
        l1 = s1.length();l2 = s2.length();
        int a[10];
        int t = 0;
        //cout<<s1<<"ss"<<endl<<s2<<"aa"<<endl;
        for(int i = 0;i<l1;i++){
            if(s1[i]!='<'&&s1[i]!='>')cout<<s1[i];
            else{a[t++] = i;}
        }
        cout<<endl;
        //for(int i = 0;i<4;i++){cout<<a[i]<<" ";}
        for(int j = 0;j<l2;j++){
            if(s2[j] == s2[j+1]&&s2[j+1] == s2[j+2]&&s2[j+2] == '.'){
                for(int i = a[2]+1;i<a[3];i++)cout<<s1[i];
                for(int i = a[1]+1;i<a[2];i++)cout<<s1[i];
                for(int i = a[0]+1;i<a[1];i++)cout<<s1[i];
                for(int i = a[3]+1;i<l1;i++)cout<<s1[i];
                j+=3;
            }
            else cout<<s2[j];
        }
        cout<<endl;
    }
}
/**
3
<schn>abel <n>ur
wenn es haengt an der ...
weil wir zu spaet zur <>oma <k>amen
verpassten wir das ...
<d>u <b>ist
...

*/
