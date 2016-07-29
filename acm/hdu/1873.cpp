#include<bits/stdc++.h>
using namespace std;
#define sa(x) scanf("%d",&x)
const int maxn = 1005;
struct node{
    int pri;
    int id;
    bool operator < (const node a) const {
        if(pri == a.pri)return id>a.id;
        return pri<a.pri;
    }
}g;

int main(){
    string a;
    int n;
    while(cin>>n){
        int cnt = 1;
       priority_queue<node> q[3];
       for(int i = 0;i<n;i++){
        cin>>a;
        if(a == "OUT"){
            int d;
            cin>>d;
            d--;
            if(q[d].empty()){cout<<"EMPTY"<<endl;}
            else{
                g = q[d].top();
                q[d].pop();
                cout<<g.id<<endl;
            }
        }
        else{
            int d;
            cin>>d>>g.pri;
            g.id = cnt++;
            q[d-1].push(g);
        }
       }
    }

}
