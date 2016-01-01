#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    int n;
    cin>>n;
    a[1] = 2;
    a[2] = 3;
    a[3] = 5;
    int t = 3;
    for(int i = 6;i<=n;i++){
            int yn = 0;
        for(int j = 1;j<=t;j++){
            if(i%a[j] == 0)yn =1;
        }
        if(yn == 0)a[++t] = i;
    }
    for(int i = 1;i<=t;i++){
        if(a[i]<=n)cout<<a[i]<<endl;
    }
}
