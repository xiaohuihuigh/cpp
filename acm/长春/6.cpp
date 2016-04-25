#include<iostream>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;

int gcd(int n,int m){
    return m == 0?n:gcd(m,n%m);
}
int a[10010];
int main(){
    int T;
    std::ios::sync_with_stdio(0);
    cin>>T;
    int ca = 0;

    while(T--){
        long long sum = 0;
        long long n,m;
        cin>>n>>m;
        memset(a,0,sizeof(a));
        for(int i = 0;i<n;i++){
            cin>>a[i];
            int c = gcd(a[i],m);
            a[i] = c;
            }

            sort(a,a+n);
            int l = unique(a,a+n) - a;
            for(int i = 0;i<l;i++){
                for(int j = 0;j<i;j++){
                    if(a[j]!= 0&&a[i]%a[j]==0)a[i] = 0;
                }
            }
            sort(a,a+l);
            int ll = unique(a,a+l) - a;
            for(int i = 0;i<ll;i++){cout<<a[i]<<" ";}
            for(int i = 0;i<ll;i++){
                    if(a[i] == 0) continue;

                    int k = (m-1)/a[i];
                    int summ = (1+k)*k/2;
                    sum += summ*a[i];
            }
            for(int i = 0;i<ll;i++){
                for(int j = i+1;j<ll;j++){
                        if(a[i] == 0)break;
                        if(a[j] == 0)continue;
                        if(a[i]*a[j]>m)break;
                        int k = (m-1)/(a[i]*a[j]);
                        int summ = (1+k)*k/2;
                    sum -= summ*a[i]*a[j];
                }
            }
    cout<<"Case #"<<++ca<<": ";
        cout<<sum<<endl;
    }
}
