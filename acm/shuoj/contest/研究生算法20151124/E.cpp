
#include<bits/stdc++.h>
using namespace std;
int a[102][102];
int b[102][102];
int main(){
    int n;
    while(cin>>n){
        for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin>>a[i][j];
        for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin>>b[i][j];
        for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            a[i][j] +=b[i][j];
            if(j != 0)cout<<" ";
            cout<<a[i][j];
        }
        cout<<endl;
        }
    }
}
