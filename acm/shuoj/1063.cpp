#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    while(cin>>n>>m){
        long long ma = 0;
        int nn = n<m?n:m,mm = n<m?m:n;
    for(long long i = nn;i<=mm;i++){
        long long t = 0;long long num = i;
        while(num!= 1){
            //if(num<0){cout<<i<<num;break;}
            if(num%2)
                num = num*3+1;
            else num/=2;
            t++;
        }
        ma = max(ma,t);
    }
    cout<<n<<" "<<m<<" "<<1+ma<<endl;
    }

}
