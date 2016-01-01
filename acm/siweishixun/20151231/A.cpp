#include<iostream>
using namespace std;
typedef  long long ll;
ll  dp[1000];
void it(){
    dp[0 ] =1;
    for(int i = 1;i<22;i++){
    dp[i] = 0;
        for(int j = 1;j<i;j++){
            dp[i]=j*(dp[i]+dp[j-1]);
        }
    }
}
int main(){
int n;
it();
while(cin>>n){
    cout<<dp[n]<<endl;
}

}
