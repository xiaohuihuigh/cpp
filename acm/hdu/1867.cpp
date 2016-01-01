//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
const int maxn = 100005;
int Next[maxn];
void getNext(string a){
    int i = 0;int j =-1;
    Next[i] = j;
    int l=  a.size();
    while(i<l){
        if(j == -1||a[i] == a[j]){
               Next[++i] = ++j;
        }
        else j = Next[j];
    }
}
int kmp(string a,string b){
    int i = 0,j = 0;
    getNext(a);
    int al = a.size();
    int bl = b.size();
    while(i<bl){
        if(j == -1||a[j] == b[i]){
            i++;j++;
        }
        else j = Next[j];
        if( i!=bl &&j == al)
            j = Next[j];
    }
    return j;

}
int main(){
    string a,b;
    while(cin>>a>>b){
       // cout<<kmp(b,a);
       int a1 = kmp(b,a);
       int a2 = kmp(a,b);
       if(a1 == a2){
            if(a>b){
              cout<<b;
            for(int i = kmp(a,b);i<a.size();i++)
            {

                cout<<a[i];
            }
            cout<<endl;
            }
            else{
                cout<<a;
                for(int i = kmp(b,a);i<b.size();i++)
                {

                    cout<<b[i];
                }
                cout<<endl;
            }

        }
       else if(a1>a2){
            cout<<a;
            for(int i = kmp(b,a);i<b.size();i++)
            {

                cout<<b[i];
            }
            cout<<endl;
       }
        else{
             cout<<b;
            for(int i = kmp(a,b);i<a.size();i++)
            {

                cout<<a[i];
            }
            cout<<endl;
        }




    }
}
