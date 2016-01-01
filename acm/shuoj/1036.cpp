#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main(){
    int n;
    cin>>n;
        int cnt = 1;
    for (int i = 0;i<100;i++)
        for(int j = i;j>=0;j--)
            a[j][i-j] = cnt++;
    for (int i = 0;i<n;i++){
        for(int j =0;i+j<n;j++){
                if(j!= 0)cout<<" ";
            cout<<a[i][j];
        }cout<<endl;}
}
