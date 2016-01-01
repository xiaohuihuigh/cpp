#include<cstring>
#include<iostream>
using namespace std;
typedef  long long ll;
ll f[20];
ll kate(int n){
    f[0] = 1;f[1] = 0;
        for(int i = 1;i<=n;i++){
        for(int j  = 1;j<=i;j++){
            f[j] += f[j-1];
        }
    }
    return f[n];
}
int main(){
    int n;
    cin>>n;
    memset(f,0,sizeof(f));
    cout<<kate(n)<<endl;
}
