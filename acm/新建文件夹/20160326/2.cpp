#include<iostream>
#include<set>
using namespace std;
typedef long long ll;
long long num(long long x,long long l){
    while (x>=l)x/=10;
    return x;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        long long n,x;
        cin>>n>>x;
        long long l = 1;
        set<long long >s;
        while(n--)l*=10;
        s.insert(x);
        while(true){
            long long t = num(x*x,l);
            set<long long>::iterator iter = s.end();
            if(iter ==s.find(t)){s.insert(t);}
            else {break;}
            x = t;
        }
        set<long long>::iterator iter = s.begin();
        long long ans = 0;
        for(;iter!= s.end();iter++){
            ans = max(ans,*iter);
        }
        cout<<ans<<endl;
        s.clear();
    }
}
