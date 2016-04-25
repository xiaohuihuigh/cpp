
#include<bits/stdc++.h>
using namespace std;
long long a[50000];
long long lcd(int a,int b){
    while(1){
        if(a>b)a = a%b;
        else b = b%a;
        if(a == 0) return b;
        if(b == 0) return a;
            }
    }
int main(){
    int T;
    cin>>T;
    while(T--){
            int i = 0;
       Loop: cin>>a[i++];
      char  c = getchar();
        if(c !='\n')
            goto Loop;
        long long  lcm = 1;
        for(int j = 0;j<i;j++){
           if(lcm%a[j] != 0){
            lcm = lcm*a[j]/lcd(lcm,a[j]);
           }
        }
        cout<<lcm<<endl;
    }
}
