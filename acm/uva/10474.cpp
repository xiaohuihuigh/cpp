
#include<bits/stdc++.h>
using namespace std;
int a[10500];
int main(){
    int n,m;
    while(cin>>n>>m&&n&&m){
            memset(a,0,sizeof(a));
        for(int i = 0;i<n;i++){
            int s;
            cin>>s;
            a[s]++;
        }
        for(int i = 1;i<10;i++){
            a[i] = a[i]+a[i-1];
            cout<<i<<" "<<a[i]<<endl;
        }
        for(int i = 0;i<m;i++){
            int b;
            cin>>b;
            if(a[b]!=a[b-1]){
                cout<<a[b-1]+1<<endl;
            }
            else cout<<"not"<<endl;
        }

    }
}
