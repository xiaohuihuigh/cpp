
#include<iostream>
using namespace std;
int main (){
    int n,m;
    while(cin>>n>>m&&n&&m){
        n*=100;
        int yn = 0;
        for(int i = 0;i<100;i++){
            if((n+i)%m == 0){
                if(yn != 0)cout<<" ";
                if(i<=9){
                    cout<<"0"<<i;
                }
                else cout<<i;
                yn++;
            }
        }
        cout<<endl;
    }
    return 0;
}
