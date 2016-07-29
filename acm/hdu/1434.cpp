#include<bits/stdc++.h>
using namespace std;
#define sa(x) scanf("%d",&x)
const int maxn = 10005;
struct node{
    string name;
    int rp;
    bool operator < (const node a) const {
        if(rp == a.rp)return name<a.name;
        return rp>a.rp;
    }
}g;

int main(){
    string a;
    int n,m;
    while(cin>>n>>m){
        priority_queue<node> q[maxn];

        for(int i = 1;i<=n;i++){
            int x;
            cin>>x;
            for (int j = 0;j<x;j++){
            	cin>>g.name>>g.rp;
            	q[i].push(g);
            }
        }
        for(int i = 0;i<m;i++){
            string a;
            cin>>a;
            if(a == "GETOUT"){
                int d;
                cin>>d;
                g = q[d].top();
                q[d].pop();
                cout<<g.name<<endl;
            }
            else if(a == "JOIN"){
                int d1,d2;
                cin>>d1>>d2;
                while(!q[d2].empty()){
                    g = q[d2].top();
                    q[d2].pop();
                    q[d1].push(g);
                }
            }
            else{
                int d;
                cin>>d>>g.name>>g.rp;
                q[d].push(g);
            }
        }
    }

}
