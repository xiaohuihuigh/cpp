

#include<iostream>
using namespace std;
int s[1000];
int l[1000];
int r[1000];
void link(int x,int y){
    r[x] = y;
    l[y] = x;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,t;
        cin>>n>>t;
        cout<<n<<t;
        int nn  =n;
        for(int i = 0;i<=n;i++){
            l[i] = i-1;
            r[i] = i+1;
        }
        char a;int x,y;
        while(t--){
        cin>>a>>x>>y;
        cout<<a<<x<<y;
        link(l[x],r[x]);
        if(a == 'A'){
            link(l[y],x);
            link(x,y);
        }
        else if(a == 'B'){link(x,r[y]);link(y,x);}
        else {
            if(x == 0){
                cout<<l[y]<<endl;
            }
            else{
                    cout<<r[y]<<endl;
            }
            }

        }
        }
        }

