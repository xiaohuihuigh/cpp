#include<bits/stdc++.h>
using namespace std;
int lb(int x) {return x&(-x);}
const int maxn = 100005;
template<typename X>
struct tree_arr{
    X bits[maxn];
    int n;
    void init(int s){n = s;for(int i = 0;i<=n;i++)bits[i] = 0;}
    void add(int x,X y){while(x<=n){bits[x]+=y;x+=lb(x);}}
    X sum(int x){X s = 0;while(x>0){s+=bits[x];x-=lb(x);}return s;}
};
tree_arr<int > Tr;
int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n&&n){
        Tr.init(n);
        for(int i = 0;i<n;i++){
            int x,y;
            cin>>x>>y;
            Tr.add(x,1);Tr.add(y+1,-1);
        }
        for(int i = 1;i<=n;i++){
            i!=n?cout<<Tr.sum(i)<<" ":cout<<Tr.sum(i)<<endl;

        }
    }
}
