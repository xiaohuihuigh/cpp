
#include<iostream>
using namespace std;
int l[10010];
int r[10010];
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
        for(int i = 1;i<=n;i++){
            l[i] = i-1;
            r[i] = i+1;
        }l[1] = n;r[n] = 1;//¹æ¶¨
        char a;int x,y;
        while(t--){
            cin>>a>>x>>y;

            if(a == 'A'){
            link(l[x],r[x]);
            link(l[y],x);
            link(x,y);
        }
        else if(a == 'B'){link(l[x],r[x]);link(x,r[y]);link(y,x);}
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
    return 0;
}


