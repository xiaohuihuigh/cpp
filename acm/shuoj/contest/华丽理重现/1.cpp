#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int a[100005];
int main(){
    int T;
    //for(int i = 0;i<100000;i++)cout<<"1";
    cin>>T;int ca = 0;
    getchar();
    while(T--){
       string s;
       getline(cin,s);
      // cout<<s<<endl;
     //  s = s+'a';
     memset(a,0,sizeof(a));
       int j = 0;a[0] = 1;
       for(int i = 1;i<s.length();i++){
            if(s[i] == s[i-1])a[j]++;
            else a[++j] = 1;
       }
       long long ma = 0;long long sum = 0;
       int maxi = 0;
       for(int i = 0;i<=j;i++){
            maxi = max(maxi,a[i]);
            sum += a[i]*a[i];
       }
      // cout<<"j"<<j<<endl;
       if(j == 0){ cout<<"Case #"<<++ca<<": ";cout<<a[0]*a[0]<<endl;continue;}
       for(int i = 0;i<=j;i++){
           // cout<<a[i]<<endl;
           if(i ==0&&a[i] == 1)
             ma = max(ma,sum - 1 -a[i+1]*a[i+1]+(1+a[i+1])*(1+a[i+1]));

            else if(i<j&&a[i] == 1)
                   ma = max(ma,sum - 1 - a[i-1]*a[i-1]-a[i+1]*a[i+1]+(1+a[i-1]+a[i+1])*(1+a[i-1]+a[i+1]));
           else if(i ==j&&a[i] == 1)
             ma = max(ma,sum - 1 - a[i-1]*a[i-1]+(1+a[i-1])*(1+a[i-1]));

       }
       for(int i = 0;i<=j;i++){
            if(a[i] == maxi){
                    if(i == 0)
                        ma = max(ma,sum - a[i]*a[i] - a[i+1]*a[i+1]+(a[i+1] - 1)*(a[i+1] - 1)+(a[i]+1)*(a[i]+1));
                    else if(i == j)
                        ma = max(ma,sum - a[i]*a[i] - a[i-1]*a[i-1]+(a[i-1] - 1)*(a[i-1] - 1)+(a[i]+1)*(a[i]+1));
                    else{
                    ma = max(ma,sum - a[i]*a[i] - a[i+1]*a[i+1]+(a[i+1] - 1)*(a[i+1] - 1)+(a[i]+1)*(a[i]+1));
                    ma = max(ma,sum - a[i]*a[i] - a[i-1]*a[i-1]+(a[i-1] - 1)*(a[i-1] - 1)+(a[i]+1)*(a[i]+1));
                    }
            }
       }
        cout<<"Case #"<<++ca<<": ";
        cout<<max(ma,sum)<<endl;
    }
}

