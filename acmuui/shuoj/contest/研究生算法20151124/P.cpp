#include<bits/stdc++.h>
using namespace std;
int dir[4][2] = {{1,2},{2,1},{-2,1},{-1,2}};
int maps[25][25];
int main(){
   int m,n;
   while(cin>>n>>m){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    d -= b;
    a--;b = 0;c--;
    memset(maps,-1,sizeof(maps));
    maps[a][b] = 0;

    queue<int> Q;
    while(!Q.empty())Q.pop();
    Q.push(a*n+b);
    while(!Q.empty()){
        int t = Q.front();Q.pop();
        int x = t/n,y = t%n;
        for(int i = 0;i<4;i++){
                    int tx,ty;
                    tx = x+dir[i][0];ty = y+dir[i][1];
                    if(tx>=n||ty>=m||tx<0||ty<0||maps[tx][ty] != -1)continue;
                    if(tx == c&&ty == d) {
                      //       cout<<x<<" "<<y<<" "<<tx<<" "<<ty<<endl;
                            maps[tx][ty] = maps[x][y]+1;
                            goto END;
                    }
                    maps[tx][ty] = maps[x][y] +1;
                  //  cout<<x<<" "<<y<<" "<<tx<<" "<<ty<<endl;
                    Q.push(tx*n+ty);
        }
    }
    END:
        if(maps[c][d] == -1 )cout<<"Impossible"<<endl;
        else cout<<maps[c][d]<<endl;
   }
}
