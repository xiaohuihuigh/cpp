#include<bits/stdc++.h>
using namespace std;
#define sa(x) scanf("%d",&x)
const int maxn = 1005;
struct node{
    string s;
    int para;
    int pri;
    int id;
    bool operator < (const node a) const {
        if(pri == a.pri)return id>a.id;
        return pri>a.pri;
    }
}g;
priority_queue<node> q;
int main(){
    string a;int cnt = 0;
    while(cin>>a){
        if(a == "GET"){
            if(q.empty()){cout<<"EMPTY QUEUE!"<<endl;}
            else{
                g = q.top();
                q.pop();
                cout<<g.s<<" "<<g.para<<endl;
            }
        }
        else{
            cin>>g.s>>g.para>>g.pri;
            g.id = cnt++;
            q.push(g);
        }
    }
}
