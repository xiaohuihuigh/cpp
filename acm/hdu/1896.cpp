#include<bits/stdc++.h>
using namespace std;
#define sa(x) scanf("%d",&x)
const int maxn = 10005;
struct node{
    int pos;
    int dis;
    bool operator < (const node a) const {
        if(pos == a.pos)return dis>a.dis;
        return pos>a.pos;
    }
}g;

int main(){
    int T;
    cin>>T;
    while(T--){
        priority_queue<node> q;
        int n;
        cin>>n;
        for (int i = 0;i<n;i++){
        	cin>>g.pos>>g.dis;
        	q.push(g);
        }
        int num = 0;
        while(!q.empty()){
            g = q.top();q.pop();
            num++;
            if(num&1){
                g.pos = g.pos+g.dis;
                q.push(g);
            }
        }
        cout<<g.pos<<endl;
    }

}
